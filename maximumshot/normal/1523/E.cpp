#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = inf + 7;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void _inc(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void _dec(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int _div(int a, int b) {
    return _mul(a, _binpow(b, mod - 2));
}

int fast(int n, int k) {
    int N = n + k - 1;
    vector<int> rev(N + 1);
    for (int i = 1; i <= n; i++)
        rev[i] = _binpow(i, mod - 2);
    vector<int> fact(N + 1), rfact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = _mul(fact[i - 1], i);
    rfact[N] = _binpow(fact[N], mod - 2);
    for (int i = N - 1; i >= 0; i--)
        rfact[i] = _mul(rfact[i + 1], i + 1);
    auto CNK = [&](int nn, int kk) -> int {
        if (nn < kk) return 0;
        return _mul(fact[nn], _mul(rfact[kk], rfact[nn - kk]));
    };
    vector<int> c_sets(N + 1), f(N + 10);
    for (int x = 1; x * k <= N && x <= n; x++) {
        c_sets[x] = CNK(N - x * (k - 1), x);
//        cout << x << " : " << c_sets[x] << "\n";
        f[x] = _mul(_mul(_mul(fact[x], fact[n - x]), rfact[n]), c_sets[x]);
    }
    int res = 0;
    for (int x = 1; x <= N; x++) {
        int p = _sub(f[x], f[x + 1]);
        _inc(res, _mul(p, x + 1));
    }
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int res = fast(n, k);
        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}