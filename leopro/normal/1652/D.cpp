#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct ModInt {
    static const int MOD = 998244353;
    int value;

    ModInt(int x) : value(x) {}

    ModInt operator+(ModInt other) const {
        int res = value + other.value;
        if (res >= MOD) res -= MOD;
        return res;
    }

    ModInt &operator+=(ModInt other) { return *this = *this + other; }

    ModInt &operator-=(ModInt other) { return *this = *this - other; }

    ModInt operator-(ModInt other) const {
        int res = value - other.value;
        if (res < 0) res += MOD;
        return res;
    }

    ModInt operator*(ModInt other) const { return (value * 1LL * other.value) % MOD; }

    ModInt &operator*=(ModInt other) { return *this = *this * other; }

    ModInt power(int exp) {
        if (exp == 0) return 1;
        if (exp % 2 == 1) return *this * power(exp - 1);
        ModInt h = power(exp / 2);
        return h * h;
    }

    ModInt operator/(ModInt other) const { return *this * other.power(MOD - 2); }

    ModInt &operator/=(ModInt other) { return *this = *this / other; }
};

template<typename T>
void setMax(T &t, T other) { t = max(t, other); }

template<typename T>
void setMin(T &t, T other) { t = min(t, other); }

#define answerExit(ans) { cout << (ans) << '\n'; exit(0); }
#define answerReturn(ans) { cout << (ans) << '\n'; return; }

struct edge {
    int nxt;
    vector<int> t, b;
    int T, B;

    edge(int nxt, vector<int> t, vector<int> b, int T, int B) : nxt(nxt), t(std::move(t)), b(std::move(b)), T(T),
                                                                B(B) {}
};

void solve() {
    int n;
    cin >> n;
    vector<int> minPrime(n + 1);
    vector<int> primes;
    vector<vector<int>> occ(n + 1);
    for (int p = 2; p <= n; ++p) {
        if (minPrime[p] == 0) {
            minPrime[p] = p;
            primes.push_back(p);
        }
        int y = p;
        while (y > 1) {
            occ[p].push_back(minPrime[y]);
            y /= minPrime[y];
        }
        for (int x : primes) {
            if (x * p > n || x > minPrime[x]) {
                break;
            }
            minPrime[p * x] = x;
        }
    }
    vector<vector<edge>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        --u, --v;
        vector<int> xp = occ[x], yp = occ[y];
        g[u].emplace_back(v, xp, yp, x, y);
        g[v].emplace_back(u, yp, xp, y, x);
    }
    vector<int> maxPrime(n + 1), curPrime(n + 1);
    vector<ModInt> ratio(n, 0);
    auto dfs = [&](auto dfs, int cur, int prev) -> void {
        for (auto &[nxt, t, b, T, B] : g[cur]) {
            if (nxt == prev) continue;
            for (int x : b) setMax(maxPrime[x], --curPrime[x]);
            for (int x : t) setMax(maxPrime[x], ++curPrime[x]);
            ratio[nxt] = ratio[cur] * B / T;
            dfs(dfs, nxt, cur);
            for (int x : t) --curPrime[x];
            for (int x : b) ++curPrime[x];
        }
    };
    ratio[0] = 1;
    dfs(dfs, 0, 0);
    ModInt coef = 1;
    for (int i = 0; i <= n; ++i) {
        coef *= ModInt(i).power(maxPrime[i]);
    }
    answerReturn((coef * accumulate(ratio.begin(), ratio.end(), ModInt(0))).value);
}