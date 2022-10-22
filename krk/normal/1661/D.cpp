#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n, k;
ll b[Maxn];
ll BITsum[Maxn], BITcnt[Maxn];
ll res;

ll Get(ll BIT[], int x)
{
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void Add(ll BIT[], int x, ll val)
{
    for (int i = x; i <= n; i += i & -i)
        BIT[i] += val;
}

void addRange(ll BIT[], int x, ll val)
{
    Add(BIT, x, val);
    Add(BIT, x + k, -val);
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &b[i]);
    for (int i = n - k + 1; i > 1; i--) {
        int ind = i + k - 1;
        ll lft = b[ind] - Get(BITcnt, ind) * (ind + 1) + Get(BITsum, ind);
        if (lft > 0) {
            ll nd = (lft - 1) / k + 1;
            res += nd;
            addRange(BITcnt, i, nd);
            addRange(BITsum, i, nd * i);
        }
    }
    ll mx = 0;
    for (int i = 1; i <= k; i++) {
        ll lft = b[i] - Get(BITcnt, i) * (i + 1) + Get(BITsum, i);
        if (lft > 0)
            mx = max(mx, (lft - 1) / i + 1);
    }
    res += mx;
    cout << res << endl;
    return 0;
}