#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 105;
const int Maxd = 4;

int n;
char B[Maxd][Maxn][Maxn];
int res = Inf;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < n; j++)
            scanf("%s", B[i][j]);
    for (int z = 0; z < 1 << 4; z++) if (__builtin_popcount(z) == 2) {
        int cand = 0;
        for (int i = 0; i < Maxd; i++) {
            char nd = (z & 1 << i)? '0': '1';
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if ((j + k) % 2 != 0 && B[i][j][k] == nd ||
                        (j + k) % 2 == 0 && B[i][j][k] != nd)
                        cand++;
        }
        res = min(res, cand);
    }
    cout << res << endl;
    return 0;
}