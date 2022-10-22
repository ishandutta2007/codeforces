#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;

int T;
int n, m, k;
int X[Maxn], Y[Maxn];
map <int, int> vert, hor;
map <ii, int> vertp, horp;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &X[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &Y[i]);
        vert.clear(); hor.clear();
        vertp.clear(); horp.clear();
        ll res = 0;
        for (int i = 0; i < k; i++) {
            int xp, yp; scanf("%d %d", &xp, &yp);
            int ind1 = lower_bound(X, X + n, xp) - X;
            int ind2 = lower_bound(Y, Y + m, yp) - Y;
            if (ind1 < n && X[ind1] == xp)
                if (ind2 < m && Y[ind2] == yp) continue;
                else {
                    vert[ind2]++;
                    vertp[ii(ind1, ind2)]++;
                }
            else {
                hor[ind1]++;
                horp[ii(ind2, ind1)]++;
            }
        }
        for (auto it: vert)
            res += ll(it.second) * (it.second - 1) / 2ll;
        for (auto it: hor)
            res += ll(it.second) * (it.second - 1) / 2ll;
        for (auto it: vertp)
            res -= ll(it.second) * (it.second - 1) / 2ll;
        for (auto it: horp)
            res -= ll(it.second) * (it.second - 1) / 2ll;
        printf("%I64d\n", res);
    }
    return 0;
}