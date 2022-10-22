#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Inf = 1000000000;

int T;
int n, m;
char B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int mnx = Inf, mxx = -Inf;
        int mny = Inf, mxy = -Inf;
        for (int i = 0; i < n; i++) {
            scanf("%s", B[i]);
            for (int j = 0; j < m; j++)
                if (B[i][j] == 'B') {
                    int x = i + j, y = i - j;
                    mnx = min(mnx, x);
                    mxx = max(mxx, x);
                    mny = min(mny, y);
                    mxy = max(mxy, y);
                }
        }
        int res = Inf;
        int bi, bj;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int x = i + j, y = i - j;
                int cand = max({mxx - x, x - mnx, mxy - y, y - mny});
                if (cand < res) {
                    res = cand;
                    bi = i; bj = j;
                }
            }
        printf("%d %d\n", bi + 1, bj + 1);
    }
    return 0;
}