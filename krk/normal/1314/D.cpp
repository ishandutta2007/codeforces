#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000007;
const int Maxn = 82;
const int Maxd = 5;

int n, k;
int B[Maxn][Maxn];
ii best[Maxn][Maxn][Maxd];
int tk[Maxn];
int res = Inf;
int seq[Maxn], slen;

int getBest(int a, int b)
{
    for (int i = 0; i < Maxd; i++)
        if (best[a][b][i].second == -1 || !tk[best[a][b][i].second]) return best[a][b][i].first;
    return Inf;
}

void Gen(int lft, int lst)
{
    if (lft == 0) {
        seq[slen++] = 0;
        int cand = 0;
        for (int i = 0; i + 1 < slen; i++) {
            int add = getBest(seq[i], seq[i + 1]);
            if (add >= Inf) { cand = Inf; break; }
            else cand += add;
        }
        res = min(res, cand);
        slen--;
    } else {
        for (int i = 0; i < n; i++) {
            tk[i]++;
            seq[slen++] = i;
            Gen(lft - 1, i);
            tk[i]--;
            slen--;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            fill(best[i][j], best[i][j] + Maxd, ii(Inf, -1));
            for (int k = 0; k < n; k++) if (k != i && k != j) {
                ii cand = ii(B[i][k] + B[k][j], k);
                for (int d = Maxd - 1; d >= 0; d--)
                    if (cand < best[i][j][d]) {
                        if (d + 1 < Maxd) best[i][j][d + 1] = best[i][j][d];
                        best[i][j][d] = cand;
                    } else break;
            }
        }
    seq[slen++] = 0; tk[0]++;
    Gen(k / 2 - 1, 0);
    printf("%d\n", res);
    return 0;
}