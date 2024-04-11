//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, sy, sl, sr, lr[400005], len[200005], qx, qy;

double trans(int x1, int y1, int x2, int y2, int y)
{
    return double(x1) + double(x2 - x1) / double(abs(y1 - y2)) * double(abs(y1 - y));
}

int bsL(int L, int R)
{
    if (L == R)
        return L;

    int mid = (L + R + 1) / 2;

    double tr = trans(qx, qy, lr[mid], 0, sy);
    if (tr < sl)
        return bsL(mid, R);
    else
        return bsL(L, mid - 1);
}

int bsR(int L, int R)
{
    if (L == R)
        return L;
    int mid = (L + R) / 2;
    double tr = trans(qx, qy, lr[mid], 0, sy);
    if (sr < tr)
        return bsR(L, mid);
    else
        return bsR(mid + 1, R);
}

int main()
{
    fast;
    cin >> sy >> sl >> sr;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lr[2 * i] >> lr[2 * i + 1];
        len[i] = lr[2 * i + 1] - lr[2 * i];
    }
    for (int i = 1; i <= n + 1; i++)
        len[i] += len[i - 1];

    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> qx >> qy;
        int left = bsL(1, 2 * n + 1), right = bsR(1, 2 * n + 2);

        //cout << left << " " << right << '\n';
        double res = 0.0;
        res += trans(0, qy, len[(right / 2) - 1] - (len[left / 2]), 0, sy) ;
        if (right - left == 1 && right % 2)
            res = sr - sl;
        else
        {
            if (right % 2)
                res += double(sr) - trans(qx, qy, lr[right - 1], 0, sy);
            if (!(left % 2))
                res += trans(qx, qy, lr[left + 1], 0, sy) - double(sl);
        }
        cout << fixed << setprecision(12) << res << '\n';
    }
}