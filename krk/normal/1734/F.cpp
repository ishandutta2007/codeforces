#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct pos {
    ll lef, rig, len;
    bool inv;
    pos() {}
    pos(ll lef, ll rig, ll len, bool inv): lef(lef), rig(rig), len(len), inv(inv) {}
    bool operator<(const pos &oth) const {
        if (lef != oth.lef) return lef < oth.lef;
        if (rig != oth.rig) return rig < oth.rig;
        if (len != oth.len) return len < oth.len;
        return inv < oth.inv;
    }
};

int T;
map <pos, ll> M;

ll F(ll lef, ll rig, ll len, bool inv)
{
    if (lef == rig) return inv? len: 0;
    if (lef > rig) swap(lef, rig);
    auto p = pos(lef, rig, len, inv);
    auto it = M.find(p);
    if (it != M.end()) return it->second;
    ll siz = 1;
    while (2 * siz <= rig) siz *= 2ll;
    ll rem = 2 * siz - rig;
    ll res;
    if (len <= rem) res = F(lef, rig - siz, len, !inv);
    else res = F(lef, rig - siz, rem, !inv) + F(lef + rem, 2 * siz, len - rem, inv);
    M.insert(make_pair(p, res));
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        ll n, m; scanf("%I64d %I64d", &n, &m);
        printf("%I64d\n", F(0, n, m, false));
    }
    return 0;
}