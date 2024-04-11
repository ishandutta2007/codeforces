#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
ll has[Maxn];
ll lft[Maxn];
ll res;

ll Sum(ll a, ll b, ll hm) { return (a + b) * hm / 2; }

int getMaxRight(int cols)
{
    int res = cols;
    int improv = m - cols * n;
    for (int i = 1; i <= n; i++) {
        ll got = Sum(i, i + ll(cols - 1) * n, cols);
        if (got > has[i]) return -1;
        res = min(ll(res), improv? (has[i] - got) / improv: cols);
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &has[i]);
    for (int j = 1; j <= m / n; j++) {
        int R = getMaxRight(j);
        if (R == -1) break;
        int L = j - R;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            ll add = Sum(m - (n - i), m - (n - i) - ll(R - 1) * n, R);
            sum += add;
            lft[i] = has[i] - add;
        }
        int col = L;
        ll best = m - R * n;
        int ind = n;
        while (col > 0) {
            best = min(best, lft[ind] - Sum(ind, ind + ll(col - 2) * n, col - 1));
            if (best == ind + ll(col - 1) * n) {
                sum += Sum(1, best, best);
                break;
            }
            sum += best;
            lft[ind] -= best;
            best--;
            if (--ind == 0) {
                col--;
                ind = n;
            }
        }
        res = max(res, sum);
    }
    cout << res << endl;
    return 0;
}