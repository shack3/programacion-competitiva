#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ordenar(char *string, int ad);

char *itoA(int numero, char *string);

int main() {
    int casos, i, ascendente, descendente, numero, contador;
    char c[4];
    char *aux = malloc(4 * sizeof(char));
    gets(c);
    casos = strtol(c, NULL, 10);
    for (i = 0; i < casos; i++) {
        gets(aux);
        contador = 0;
        do {
            numero = strtol(aux, NULL, 10);
            if (numero != 6174) {
                ascendente = strtol(ordenar(aux, 0), NULL, 10);
                descendente = strtol(ordenar(aux, 1), NULL, 10);
                if (ascendente > descendente && ascendente != descendente) {
                    numero = ascendente - descendente;
                } else if (ascendente < descendente && ascendente != descendente)
                    numero = descendente - ascendente;
                else {
                    contador = 8;
                    break;
                }
                aux = itoA(numero, aux);
                contador++;
            }
        } while (numero != 6174);
        printf("%d\n", contador);
    }
    return 0;
}

char *ordenar(char *string, int ad) {
    int i, j;
    char *resultado = string;
    char temp;

    for (i = 0; i < strlen(resultado) - 1; i++) {
        for (j = i + 1; j < strlen(resultado); j++) {
            if (ad == 1 && resultado[i] > resultado[j]) {
                temp = resultado[i];
                resultado[i] = resultado[j];
                resultado[j] = temp;
            }
            if (ad == 0 && resultado[i] < resultado[j]) {
                temp = resultado[i];
                resultado[i] = resultado[j];
                resultado[j] = temp;
            }
        }
    }
    return resultado;
}

char *itoA(int numero, char *string) {
    char *resultado = string;
    int i, auxiliar = numero, loop = (int)strlen(resultado);
    for (i = loop - 1; i >= 0; i--) {
        resultado[i] = (char) (auxiliar % 10 + 48);
        auxiliar = auxiliar / 10;
    }
    return resultado;
}

