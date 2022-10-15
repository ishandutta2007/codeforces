#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
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

const int N = 3e5 + 5;

int sum[N];

int get(int f[], int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += f[pos];
    }
    return res;
}

void upd(int f[], int pos, int delta = 1) {
    for (; pos < N; pos |= pos + 1) {
        f[pos] += delta;
    }
}

pair<int, int> t[N * 4];
int lazy[N * 4];

void build(vector<int> a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = { a[tl], tl };
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

void push(int v) {
    t[v*2].first += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1].first += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v].first += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {1e9,1e9};
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {
    int n;
    cin >> n;
    vector<int> primes;
    for (int i = 2; i < 59; i++) {
        int ok = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            primes.push_back(i);
        }
    }
    int m = primes.size();
    int topkek = 1 << m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(topkek, 1e9));
    vector<vector<int>> way(n + 1, vector<int>(topkek, -1));

    vector<int> good;
    vector<vector<int>> precalc(topkek);
    for (int mask = 0; mask < topkek; mask++) {
        int val = 1;
        vector<int> cur;
        for (int i = 0; i < m && val <= 1000; i++) {
            if (mask >> i & 1) {
                val *= primes[i];
                cur.push_back(primes[i]);
            }
        }
        if (val < 59) {
            good.push_back(mask);
            precalc[mask].push_back(val);
            vector<int> extra(cur.size());
            function<void(int, int)> rec = [&](int i, int prod) {
                if (i == extra.size()) {
                    if (prod < 59) {
                        precalc[mask].push_back(prod);
                        return;
                    }
                }
                while (prod < 59) {
                    rec(i + 1, prod);
                    prod *= cur[i];
                }
            };
            rec(0, val);
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < topkek; mask++) {
            for (int sub : good) {
                if ((mask | sub) != mask) continue;
                int val = precalc[sub][0];
                for (int j : precalc[sub]) {
                    if (abs(a[i] - j) < abs(a[i] - val)) {
                        val = j;
                    }
                }
                if (dp[i - 1][mask ^ sub] + abs(val - a[i]) < dp[i][mask]) {
                    dp[i][mask] = dp[i - 1][mask ^ sub] + abs(val - a[i]);
                    way[i][mask] = sub;
                }
            }
        }
    }
    int best = 0;
    for (int mask = 0; mask < topkek; mask++) {
        if (dp[n][mask] < dp[n][best]) {
            best = mask;
        }
    }
    vector<int> b(n);
    for (int i = n - 1; i >= 0; i--) {
        int mask = way[i + 1][best];
        int val = precalc[mask][0];
        for (int j : precalc[mask]) {
            if (abs(a[i + 1] - j) < abs(a[i + 1] - val)) {
                val = j;
            }
        }
        b[i] = val;
        best ^= mask;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i + 1 == n];
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