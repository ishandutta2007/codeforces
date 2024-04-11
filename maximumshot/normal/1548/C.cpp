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

vector<int> slow(int n, int q, vector<int> xs) {
    vector<int> fact(3 * n + 1), rfact(3 * n + 1);
    fact[0] = 1;
    for (int i = 1; i < (int) fact.size(); i++)
        fact[i] = _mul(fact[i - 1], i);
    rfact.back() = _binpow(fact.back(), mod - 2);
    for (int i = (int) rfact.size() - 2; i >= 0; i--)
        rfact[i] = _mul(rfact[i + 1], i + 1);
    vector<int> res(q);
    for (int it = 0; it < q; it++) {
        int x = xs[it];
        for (int i = (x + 2) / 3; i <= n; i++)
            _inc(res[it], _mul(fact[3 * i], rfact[3 * i - x]));
        res[it] = _mul(res[it], rfact[x]);
    }
    return res;
}

vector<int> fast(int n, int q, vector<int> xs) {
    int N = 3 * n + 10;
    vector<int> fact(N), rfact(N);
    fact[0] = 1;
    for (int i = 1; i < (int) fact.size(); i++)
        fact[i] = _mul(fact[i - 1], i);
    rfact.back() = _binpow(fact.back(), mod - 2);
    for (int i = (int) rfact.size() - 2; i >= 0; i--)
        rfact[i] = _mul(rfact[i + 1], i + 1);
    vector<int> res(q);
    int r3 = _binpow(3, mod - 2);
    vector<int> dp(3 * n + 1);
    dp[0] = n + 1;
    for (int x = 1; x <= 3 * n; x++) {
        int sm = _mul(fact[3 * n], _mul(rfact[x], rfact[3 * n - x]));
        dp[x] = _mul(sm, n);
        int tmp = 0;
        {
            int hlp = 0;
            _dec(hlp, dp[x - 1]);
            _inc(hlp, _mul(fact[3 * n], _mul(rfact[x - 1], rfact[3 * n - x + 1])));
            if (x >= 2) {
                _dec(hlp, dp[x - 2]);
                _inc(hlp, _mul(fact[3 * n], _mul(rfact[x - 2], rfact[3 * n - x + 2])));
            }
            _inc(tmp, hlp);
        }
        {
            int hlp = 0;
            _inc(hlp, _mul(fact[3 * n + 2], _mul(rfact[x - 1], rfact[3 * n + 2 - (x - 1)])));
            _dec(hlp, dp[x - 1]);
            if (x >= 2)
                _dec(hlp, _mul(dp[x - 2], 2));
            if (x >= 3)
                _dec(hlp, dp[x - 3]);
            _inc(tmp, _mul(hlp, 2));
        }
        _inc(tmp, _mul(x, _mul(fact[3 * n + 1], _mul(rfact[x + 1], rfact[3 * n - x]))));
        _dec(tmp, sm);
        _dec(dp[x], _mul(tmp, r3));
    }
    for (int i = 0; i < q; i++)
        res[i] = dp[xs[i]];
    return res;
}

void work() {
    int n, q;
    cin >> n >> q;
    vector<int> xs(q);
    for (int i = 0; i < q; i++)
        cin >> xs[i];
    vector<int> res = fast(n, q, xs);
    for (auto r : res)
        cout << r << "\n";
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