#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
map < ll, ll > mp;
int sgn(ll a) {
    if (a > 0) return 1;
    if (a < 0) return -1;
    return 0;
}
int bits(ll x) {
    int b = 0;
    for (int i = 0; i <= 61; i++) {
        if (x & (1LL << i)) b++;
    }
    return b;
}
ll solve(int bit, vector < pair < ll, ll > > all, int need) {
    vector < pair < ll, ll > > f[2];
    ll sm[2] = {0, 0};
    for (auto it : all) {
        f[(it.first >> bit) & (1LL)].push_back(it);
        sm[(it.first >> bit) & (1LL)] += it.second;
    }
    if (f[1].empty()) {
        return solve(bit - 1, all, need);
    }
    if (f[0].empty()) {
        return (1LL << bit);
    }
    if (bit == 0) {
        assert(sgn(sm[1] + sm[0]) == need || sgn(-sm[1] + sm[0]) == need);
        if (sgn(sm[1] + sm[0]) == need) return 0;
        else return 1;
    }
    ll msk = solve(bit - 1, f[0], need);
    ll sa = 0;
    ll sb = 0;
    for (auto ttt : f[1]) {
        if (bits(ttt.first & msk) % 2 == 1) sa -= ttt.second;
        else sa += ttt.second;
    }
    for (auto ttt : f[0]) {
        if (bits(ttt.first & msk) % 2 == 1) sb -= ttt.second;
        else sb += ttt.second;
    }
    assert(sgn(sa + sb) == need || sgn(-sa + sb) == need);
    if (sgn(sa + sb) == need) {
        return msk;
    }
    else {
        return msk | (1LL << bit);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll msk;
        ll val;
        cin >> val >> msk;
        mp[msk] += val;
    }
    vector < pair < ll, ll > > all;
    ll sm = 0;
    for (auto it : mp) {
        if (it.second != 0) {
            all.push_back(make_pair(it.first, it.second));
            sm += it.second;
        }
    }
    if (sm > 0) cout << solve(61, all, -1);
    else cout << solve(61, all, 1);
    return 0;
}