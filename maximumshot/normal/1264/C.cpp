#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

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

const int N = 2e5 + 5;

int n, q;
int p[N];
int P[N];

void read() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
}

int fast_res[N];
int A[N], C[N];

int calc(int l, int r) { // [l, r]
    int aa = 0, bb = 0, cc = 0;
    {
        aa = _sub(A[r], A[l - 1]);
        cc = _sub(C[r], C[l - 1]);
    }
    bb = _mul(P[r], r - l + 1);
    int xx = _sub(P[l - 1], cc);
    int yy = _sub(_sum(aa, bb), _mul(l, cc));
    return _mul(yy, _binpow(xx, mod - 2));
}

void fast() {
    int r100 = _binpow(100, mod - 2);
    for (int i = 1; i <= n; i++) {
        p[i] = _mul(p[i], r100);
    }
    P[0] = 1;
    for (int i = 1; i <= n; i++) {
        P[i] = _mul(P[i - 1], p[i]);
    }
    A[0] = 0;
    for (int i = 1; i <= n; i++) {
        A[i] = A[i - 1];
        int tmp = _mul(i + 1, _mul(P[i - 1], _sub(1, p[i])));
        _inc(A[i], tmp);
    }
    C[0] = 0;
    for (int i = 1; i <= n; i++) {
        C[i] = C[i - 1];
        _inc(C[i], _mul(P[i - 1], _sub(1, p[i])));
    }
    int cur = calc(1, n);
    set<int> used = {1, n + 1};
    for (int iter = 0; iter < q; iter++) {
        int u;
        cin >> u;
        auto it = used.lower_bound(u);
        if (*it == u) {
            auto nxt = it, prv = it;
            nxt++, prv--;
            _dec(cur, calc(*prv, *it - 1));
            _dec(cur, calc(*it, *nxt - 1));
            _inc(cur, calc(*prv, *nxt - 1));
            used.erase(it);
        } else {
            auto nxt = it, prv = it;
            prv--;
            _dec(cur, calc(*prv, *nxt - 1));
            _inc(cur, calc(*prv, u - 1));
            _inc(cur, calc(u, *nxt - 1));
            used.insert(u);
        }
        fast_res[iter] = cur;
    }
}

void WORK() {
    read();
    fast();
    for (int i = 0; i < q; i++) {
        cout << fast_res[i] << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    WORK();

    return 0;
}