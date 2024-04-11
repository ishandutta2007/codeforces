#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <int, int> ii;

const int Maxn = 104;
const int Maxm = 10 * Maxn + 5;
const ld Inf = 1e60l;

ld pw[Maxn];
int tc;
int n;
vector <ii> seq;
long double C, T;
ld best[Maxn][Maxn][Maxm];

int main()
{
    pw[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw[i] = pw[i - 1] * 0.9l;
    for (int i = 0; i < Maxn; i++)
        for (int j = 0, to = 0; j <= i; j++, to += 10)
            for (int k = 0; k <= to; k++)
                best[i][j][k] = Inf;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        seq.clear();
        cin >> C >> T;
        for (int i = 0; i < n; i++) {
            int a, p; scanf("%d %d", &a, &p);
            seq.push_back(ii(a, p));
        }
        sort(seq.rbegin(), seq.rend());
        best[0][0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0, to = 0; j <= i; j++, to += 10)
                for (int k = 0; k <= to; k++) if (best[i][j][k] < Inf) {
                    best[i + 1][j][k] = min(best[i + 1][j][k], best[i][j][k]);
                    int nk = k + seq[i].second;
                    best[i + 1][j + 1][nk] = min(best[i + 1][j + 1][nk],
                                                 best[i][j][k] + seq[i].first / pw[j + 1]);
                    best[i][j][k] = Inf;
                }
        int res = 0;
        for (int j = 0, to = 0; j <= n; j++, to += 10)
            for (int k = 0; k <= to; k++) if (best[n][j][k] < Inf) {
                if (k <= res) { best[n][j][k] = Inf; continue; }
                ld t = (sqrt(C * best[n][j][k]) - 1.0l) / ld(C);
                if (t < 0) t = 0;
                if (t + best[n][j][k] / (1.0l + C * t) <= T - ld(j) * 10.0l)
                    res = k;
                best[n][j][k] = Inf;
            }
        printf("%d\n", res);
    }
    return 0;
}