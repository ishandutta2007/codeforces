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

map<pair<int, int>, int> mem;
int queries;

int ask(int i, int j) {
    assert(i != j);
    if (i > j) swap(i, j);
    if (mem.count({i, j})) {
        return mem[{i, j}];
    }
    queries++;
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return mem[{i, j}] = res;
}

void solve() {
    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    shuffle(a.begin(), a.end(), rng);
    while (a.size() > 2) {
        int mask = (1 << 13) - 1;
        int z = 0;
        int m = a.size();
        for (int it = 0; it < (m == n ? 30 : 5); it++) {
            int x = rng() % m;
            int y = rng() % m;
            while (y == x) y = rng() % m;
            int res = ask(a[x], a[y]);
            if (__builtin_popcount(res) < __builtin_popcount(mask)) {
                mask = res;
                z = x;
            }
        }
        vector<int> na;
        for (int i = 0; i < m; i++) {
            if (i == z) {
                na.push_back(a[i]);
                continue;
            }
            if ((ask(a[i], a[z]) | mask) == mask) {
                na.push_back(a[i]);
            }
        }
        a = move(na);
    }
    int zero = -1;
    if (a.size() == 1) {
        zero = a[0];
    } else {
        while (true) {
            int z = rng() % n;
            while (z == a[0] || z == a[1]) {
                z = rng() % n;
            }
            int r0 = ask(a[0], z);
            int r1 = ask(a[1], z);
            if (r0 < r1) {
                zero = a[0];
                break;
            }
            if (r0 > r1) {
                zero = a[1];
                break;
            }
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (i == zero) {
            continue;
        }
        ans[i] = ask(i, zero);
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    // cout << queries << endl;
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