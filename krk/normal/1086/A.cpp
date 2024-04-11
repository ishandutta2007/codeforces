#include <bits/stdc++.h>
using namespace std;

const int Maxd = 3;

int X[Maxd], Y[Maxd];
int best = 1000000000, bx, by;

int main()
{
    for (int i = 0; i < Maxd; i++)
        scanf("%d %d", &X[i], &Y[i]);
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++) {
            int cand = 0;
            for (int z = 0; z < Maxd; z++)
                cand += abs(X[z] - i) + abs(Y[z] - j);
            cand++;
            if (cand < best) {
                best = cand;
                bx = i; by = j;
            }
        }
    printf("%d\n", best);
    for (int z = 0; z < Maxd; z++) {
        while (X[z] != bx) {
            printf("%d %d\n", X[z], Y[z]);
            if (X[z] < bx) X[z]++;
            else X[z]--;
        }
        while (Y[z] != by) {
            printf("%d %d\n", X[z], Y[z]);
            if (Y[z] < by) Y[z]++;
            else Y[z]--;
        }
    }
    printf("%d %d\n", bx, by);
    return 0;
}