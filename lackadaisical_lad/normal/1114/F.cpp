#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 4e5 + 5;
const int M = 62;

pair<ll, ll> t[N * 4], lazy[N * 4];
ll mask[301];

pair<ll, ll> comb(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return {a.first * b.first % MOD, a.second | b.second};
}

void push(int v, int tl, int tm, int tr) {
    (t[v * 2].first *= binpow(lazy[v].first, tm - tl + 1)) %= MOD;
    t[v * 2].second |= lazy[v].second;
    lazy[v * 2] = comb(lazy[v * 2], lazy[v]);
    (t[v * 2 + 1].first *= binpow(lazy[v].first, tr - tm)) %= MOD;
    t[v * 2 + 1].second |= lazy[v].second;
    lazy[v * 2 + 1] = comb(lazy[v * 2 + 1], lazy[v]);
    lazy[v] = {1LL, 0LL};
}

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {a[tl], mask[a[tl]]};
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = comb(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        (t[v].first *= binpow(val, r - l + 1)) %= MOD;
        t[v].second |= mask[val];
        (lazy[v].first *= val) %= MOD;
        lazy[v].second |= mask[val];
    } else {
        int tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        update(v*2, tl, tm, l, min(r, tm), val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
        t[v] = comb(t[v * 2], t[v * 2 + 1]);
    }
}

pair<ll, ll> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {1LL, 0LL};
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) / 2;
    push(v, tl, tm, tr);
    return comb(query(v*2, tl, tm, l, min(r, tm)), 
                query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {
    vector<int> primes;
    for (int i = 2; i <= 300; i++) {
        int ok = 1;
        for (int j = 2; j * j <= i; j++) {
            ok &= i % j > 0;
        }
        if (ok) primes.push_back(i);
    }
    
    for (int i = 1; i <= 300; i++) {
        for (int j = 0; j < M; j++) {
            if (i % primes[j] == 0) {
                mask[i] |= 1LL << j;
            }
        }
    }

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(a, 1, 0, n - 1);
    fill(lazy, lazy + N * 4, pair<ll, ll>{1LL, 0LL});
    vector<ll> inv(M);
    for (int i = 0; i < M; i++) {
        inv[i] = (MOD + 1 - binpow(primes[i], MOD - 2)) % MOD;
    }

    while (q--) {
        string type;
        int l, r;
        cin >> type >> l >> r;
        l--, r--;
        if (type[0] == 'M') {
            int x;
            cin >> x;
            update(1, 0, n - 1, l, r, x);
        } else {
            auto res = query(1, 0, n - 1, l, r);
            for (int j = 0; j < M; j++) {
                if (res.second >> j & 1) {
                    (res.first *= inv[j]) %= MOD;
                }
            }
            cout << res.first << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}