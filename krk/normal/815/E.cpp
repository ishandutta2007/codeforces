#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
map <ll, ll> M;
ll best;

ll getBest(ll x)
{
    ll lst = x + 1;
    ll tims = 0;
    ll lft = k;
    M[x] = 1;
    auto it = M.end();
    while (true) {
        it--;
        if (lst != it->first / 2) {
            lst = it->first / 2;
            tims = 0;
        }
        tims += min(lft, it->second);
        if (lft <= it->second) {
            k = tims;
            return it->first / 2;
        }
        lft -= it->second;
        M[it->first / 2] += it->second;
        M[(it->first + 1) / 2] += it->second;
        M.erase(it++);
    }
}

ll Count(ll x)
{
    if (x / 2 < best) return 0;
    auto it = M.find(x);
    if (it == M.end()) {
        ll res = bool(x / 2 == best);
        res += Count(x / 2) + Count((x + 1) / 2);
        M.insert(make_pair(x, res));
        return res;
    }
    return it->second;
}

ll Solve(ll l, ll r)
{
    ll x = r - l;
    if (k <= Count(x / 2)) return Solve(l, l + x / 2);
    k -= Count(x / 2);
    if (x / 2 == best && k == 1) return l + x / 2;
    k -= bool(x / 2 == best);
    return Solve(l + x / 2, r);
}

int main()
{
    cin >> n >> k;
    if (k == 1) { printf("1\n"); return 0; }
    k--;
    if (k == 1) { printf("%I64d\n", n); return 0; }
    k--;
    best = getBest(n - 1);
    M.clear();
    cout << Solve(1, n) << endl;
    return 0;
}