#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const ll Inf = 4000000000000000000ll;
const int Maxn = 100005;

int T;
int n, m, k;
int x[Maxn];
vector <ii> A[Maxn], B[Maxn];
int h[Maxn];
ll res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x[i]);
            A[i].clear(); B[i].clear();
        }
        for (int i = 1; i <= k; i++) {
            int a, b, c, d; scanf("%d %d %d %d %d", &a, &b, &c, &d, &h[i]);
            B[c].push_back(ii(d, i));
            A[a].push_back(ii(b, i));
            res[i] = Inf;
        }
        k++;
        res[k] = 0; h[k] = 0;
        B[1].push_back(ii(1, k));
        k++;
        res[k] = Inf; h[k] = 0;
        A[n].push_back(ii(m, k));
        for (int i = 1; i <= n; i++) {
            sort(A[i].begin(), A[i].end());
            sort(B[i].begin(), B[i].end());
            ii best = ii(-1, -1);
            int pnt = 0;
            for (int j = 0; j < A[i].size(); j++) {
                while (pnt < B[i].size() && B[i][pnt].first <= A[i][j].first) {
                    if (res[B[i][pnt].second] < Inf) {
                        int old = best.second;
                        int nw = B[i][pnt].second;
                        if (old == -1 || res[nw] < res[old] + ll(x[i]) * (B[i][pnt].first - best.first))
                            best = B[i][pnt];
                    }
                    pnt++;
                }
                int old = best.second;
                if (old != -1)
                    res[A[i][j].second] = min(res[A[i][j].second], res[old] + ll(x[i]) * (A[i][j].first - best.first) - ll(h[A[i][j].second]));
            }
            best = ii(-1, -1);
            pnt = int(B[i].size()) - 1;
            for (int j = int(A[i].size()) - 1; j >= 0; j--) {
                while (pnt >= 0 && B[i][pnt].first >= A[i][j].first) {
                    if (res[B[i][pnt].second] < Inf) {
                        int old = best.second;
                        int nw = B[i][pnt].second;
                        if (old == -1 || res[nw] < res[old] + ll(x[i]) * (best.first - B[i][pnt].first))
                            best = B[i][pnt];
                    }
                    pnt--;
                }
                int old = best.second;
                if (old != -1)
                    res[A[i][j].second] = min(res[A[i][j].second], res[old] + ll(x[i]) * (best.first - A[i][j].first) - ll(h[A[i][j].second]));
            }

        }
        ll ans = res[k];
        if (ans < Inf) printf("%I64d\n", ans);
        else printf("NO ESCAPE\n");
    }
    return 0;
}