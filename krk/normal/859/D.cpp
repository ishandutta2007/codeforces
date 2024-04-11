#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 9;
const int Maxm = 1 << 7;

int n;
ld prob[Maxm][Maxm];
ld best[Maxn][Maxm], rew[Maxn][Maxm];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < 1 << n; j++) {
            int val; scanf("%d", &val);
            prob[i][j] = val / ld(100);
        }
    for (int i = 0; i < 1 << n; i++)
        best[0][i] = 1.0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 1 << n; j += 1 << i) {
            for (int k = j; k < j + (1 << i - 1); k++)
                for (int z = j + (1 << i - 1); z < j + (1 << i); z++) {
                    best[i][k] += best[i - 1][k] * best[i - 1][z] * prob[k][z];
                    rew[i][k] = max(rew[i][k], rew[i - 1][z]);
                    best[i][z] += best[i - 1][k] * best[i - 1][z] * prob[z][k];
                    rew[i][z] = max(rew[i][z], rew[i - 1][k]);
                }
            for (int k = j; k < j + (1 << i); k++)
                rew[i][k] += rew[i - 1][k] + best[i][k] * ld(1 << i - 1);
        }
    }
    ld best = 0;
    for (int i = 0; i < 1 << n; i++)
        best = max(best, rew[n][i]);
    cout << fixed << setprecision(15) << best << endl;
    return 0;
}