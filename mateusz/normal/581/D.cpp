#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int r;
int n, x[4], y[4], per[4];
int tab[305][305];

void wypisz() {
    printf("%d\n", r);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= r; j++) {
            printf("%c", (char)(tab[i][j] + 64));
        }
        printf("\n");
    }
}

void solve2(int a, int b) {
    for (int l = 1; l <= 2; l++, swap(x[per[2]], y[per[2]])) {
        for (int m = 1; m <= 2; m++, swap(x[per[3]], y[per[3]])) {
            if (x[per[2]] + x[per[3]] == a && y[per[2]] == b && y[per[3]] == b) {

                for (int i = 1; i <= b; i++) {
                    for (int j = 1; j <= x[per[2]]; j++) {
                        tab[i][j] = per[2];
                    }

                    for (int j = x[per[2]] + 1; j <= a; j++) {
                        tab[i][j] = per[3];
                    }
                }

                for (int i = b + 1; i <= r; i++) {
                    for (int j = 1; j <= r; j++) {
                        tab[i][j] = per[1];
                    }
                }

                wypisz();

                exit(0);
            }
        }
    }
    for (int l = 1; l <= 2; l++, swap(x[per[2]], y[per[2]])) {
        for (int m = 1; m <= 2; m++, swap(x[per[3]], y[per[3]])) {
            if (x[per[2]] + x[per[3]] == b && y[per[2]] == a && y[per[3]] == a) {

                for (int j = 1; j <= a; j++) {
                    for (int i = 1; i <= x[per[2]]; i++) {
                        tab[i][j] = per[2];
                    }
                }

                for (int j = 1; j <= a; j++) {
                    for (int i = x[per[2]] + 1; i <= b; i++) {
                        tab[i][j] = per[3];
                    }
                }

                for (int i = b + 1; i <= r; i++) {
                    for (int j = 1; j <= r; j++) {
                        tab[i][j] = per[1];
                    }
                }

                wypisz();
                exit(0);
            }
        }
    }
}

int main() {

    int f = 0;
    for (int i = 1; i <= 3; i++) {
        scanf("%d %d", &x[i], &y[i]);
        f += x[i] * y[i];
        per[i] = i;
    }

    if (sqrt(f) * sqrt(f) != f) {
        printf("-1\n");
        return 0;
    }
    r = sqrt(f);
    for (int i = 1; i <= 3; i++) {
        if (max(x[i], y[i]) > r) {
            printf("-1\n");
            return 0;
        }
    }

    do {

        if (x[per[1]] == r) {
            solve2(r, r - y[per[1]]);
        }
        swap(x[per[1]], y[per[1]]);

        if (x[per[1]] == r) {
            solve2(r, r - y[per[1]]);
        }
        swap(x[per[1]], y[per[1]]);

    } while (next_permutation(per + 1, per + 1 + 3));
    printf("-1\n");
    return 0;
}