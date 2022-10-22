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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

//    vector<int> AA(n + 1), AB(n + 1);
//
//    auto mex = [&](vector<int> vals) -> int {
//        if (vals.empty()) return 0;
//        sort(vals.begin(), vals.end());
//        if (vals.front() > 0) return 0;
//        for (int i = 0; i + 1 < (int) vals.size(); i++) {
//            if (vals[i] + 1 < vals[i + 1])
//                return vals[i] + 1;
//        }
//        return vals.back() + 1;
//    };
//
//    for (int i = 1; i <= n; i++) {
//        { // AA
//            vector<int> values;
//            for (int L = 0; L < i; L++) {
//                if (L > 0 && i - L - 1 > 0)
//                    values.push_back(AA[L] ^ AA[i - L - 1]);
//                values.push_back(AB[L] ^ AB[i - L - 1]);
//            }
//            AA[i] = mex(values);
//        }
//        { // AB
//            vector<int> values;
//            for (int L = 0; L < i; L++) {
//                if (L > 0)
//                    values.push_back(AA[L] ^ AB[i - L - 1]);
//                if (i - L - 1 > 0)
//                    values.push_back(AB[L] ^ AA[i - L - 1]);
//            }
//            AB[i] = mex(values);
//        }
//    }

//    for (int i = 0; i <= n; i++) {
//        cout << "AA " << i << " : " << (AA[i] > 0 ? "WIN" : "LOSE") << "\n";
//    }
//    cout << "\n";
//    for (int i = 0; i <= n; i++) {
//        cout << "AB " << i << " : " << (AB[i] > 0 ? "WIN" : "LOSE") << "\n";
//    }

    vector<int> fact(n + 1), rfact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = _mul(fact[i - 1], i);
    rfact[n] = _binpow(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
        rfact[i] = _mul(rfact[i + 1], i + 1);

    auto CNK = [&](int nn, int kk) -> int {
        if (nn < kk) return 0;
        return _mul(fact[nn], _mul(rfact[kk], rfact[nn - kk]));
    };

    int res = 0;

    vector<int> pw2(n + 1);
    pw2[0] = 1;
    for (int i = 1; i <= n; i++)
        pw2[i] = _mul(pw2[i - 1], 2);

    vector<int> g(n + 10);
    g[0] = g[1] = 1;
    for (int i = 2; i < (int) g.size(); i++)
        g[i] = _mul(g[i - 2], i);

    int R2 = _binpow(2, mod - 2);

    for (int holes = 0; 2 * holes <= n; holes++) {
        int rem = n - 1 - holes;
        if (rem % 2 == 0)
            continue;
        int ck = CNK(n - holes, holes);
//        int r2 = _binpow(R2, (rem - 1) / 2);
        int r2 = 1;
        int add = _mul(r2, fact[rem]);
//        add = _mul(add, (rem + 1) / 2);
        add = _mul(add, ck);
        _inc(res, add);
    }

    cout << _mul(res, 2 * n) << "\n";

    return 0;
}