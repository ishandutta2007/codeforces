#include <bits/stdc++.h>

using namespace std;

const int N = 105, M = 1e9 + 7;

int n, b, k, x;
int tmp[N][N], tmp2[N][N], A[N][N], wynik[N][N], pom[N][N];
int cnt[N], tab[50005];

void add(int &v, int w) {
    v += w;
    if (v >= M) {
        v -= M;
    }
}

void createMatrix() {

    for (int i = 0; i < x; i++) {
        tmp[10 * i % x][i]++;
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            tmp2[i][j] = cnt[(x - j + i) % x];
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < x; k++) {
                add(A[i][j], (long long)tmp2[i][k] * tmp[k][j] % M);
            }
        }
    }

    for (int i = 0; i < x; i++) {
        wynik[i][i] = 1;
    }
}

void pomnoz() {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            pom[i][j] = 0;
            for (int k = 0; k < x; k++) {
                add(pom[i][j], (long long)wynik[i][k] * A[k][j] % M);
            }
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            wynik[i][j] = pom[i][j];
        }
    }
}

void kwadrat() {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            pom[i][j] = 0;
            for (int k = 0; k < x; k++) {
                add(pom[i][j], (long long)A[i][k] * A[k][j] % M);
            }
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            A[i][j] = pom[i][j];
        }
    }
}

void powerMatrix(int b) {

    while (b >= 1) {
        if (b % 2 == 1) {
            pomnoz();
        }
        kwadrat();
        b /= 2;
    }
}

int main() {

    scanf("%d %d %d %d", &n, &b, &k, &x);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        cnt[tab[i] % x]++;
    }

    createMatrix();

    powerMatrix(b);

    printf("%d\n", wynik[k][0]);

    return 0;
}