#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 200005;

int n;
int a[Maxn];
ll m;
int my[Maxn], cnt[Maxn];

ll Get(ll L, ll cnt)
{
    ll hm = L / cnt;
    ll b = L % cnt;
    ll a = cnt - b;
    return a * hm * hm + b * (hm + 1) * (hm + 1);
}

int findLef(int L, ll val)
{
    int lef = 1, rig = L - 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Get(L, mid) - Get(L, mid + 1) >= val)
            lef = mid + 1;
        else rig = mid - 1;
    }
    return lef;
}

int Solve(ll val)
{
    int res = 0, spec = 0;
    ll cost = 0;
    for (int i = 1; i <= n; i++) {
        int L = a[i] - a[i - 1];
        int lef = findLef(L, val);
        cost += Get(L, lef);
        if (lef > 1) spec += lef - findLef(L, val + 1);
        res += lef - 1;
    }
    if (cost > m) return -1;
    ll tk = min(ll(spec), (m - cost) / val);
    res -= tk;
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%I64d", &m);
    ll lef = 0, rig = 1000000000000000000ll;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        int got = Solve(mid);
        if (got == -1) rig = mid - 1ll;
        else lef = mid + 1ll;
    }
    cout << Solve(rig) << endl;
    return 0;
}