#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 5005;

int n, m, k, p;
int a[Maxn], b[Maxn];
int lft[Maxm];

bool Solve(ll x)
{
    set <int> S;
    for (int i = 0; i < m; i++) {
        lft[i] = k;
        S.insert(i);
    }
    for (int i = 0; i < n; i++) {
        ll en = a[i] + ll(b[i]) * m;
        if (en <= x) continue;
        ll nd = en - x;
        ll cur = a[i], lef = 0;
        while (nd > 0) {
            ll y = nd % p;
            if (y == 0) y = p;
            ll tmp = y - cur;
            ll dif = tmp <= 0? 0: (tmp - 1) / b[i] + 1;
            auto it = S.lower_bound(lef + dif);
            if (it == S.end()) return false;
            cur += ll(b[i]) * (*it - lef); lef = *it;
            ll tk = min(cur, ll(p));
            nd -= tk; cur -= tk;
            if (--lft[lef] == 0) S.erase(it);
        }
    }
    return true;
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &p);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i], &b[i]);
    ll lef = 0, rig = 1000000000000000000ll;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        if (Solve(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    printf("%I64d\n", lef);
    return 0;
}