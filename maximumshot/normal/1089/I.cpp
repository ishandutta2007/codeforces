#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 405;
int mod;

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline void add_sum(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void add_sub(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void add_mul(int &x, int y) {
    x = _mul(x, y);
}

inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            add_mul(res, tmp);
        }
        pw >>= 1;
        add_mul(tmp, tmp);
    }
    return res;
}

int fact[2 * N];
int rfact[2 * N];
int F[N];
int A[N];
int B[N][N];

int CNK(int n, int k) {
    if (n < k) return 0;
    return _mul(fact[n], _mul(rfact[n - k], rfact[k]));
}

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = _mul(fact[i - 1], i);
    }
    rfact[N - 1] = _binpow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        rfact[i] = _mul(rfact[i + 1], i + 1);
    }

    F[0] = 1;
    A[0] = 1;
    B[0][0] = 1;
    for (int n = 1; n < N; n++) {
        A[n] = fact[n];
        for (int k = 1; k < n; k++) {
            add_sub(A[n], _mul(fact[k], A[n - k]));
        }
        for (int k = 1; k <= n; k++) {
            for (int t = 1; t <= n; t++) {
                add_sum(B[n][k], _mul(fact[t], B[n - t][k - 1]));
            }
        }

        F[n] = fact[n];
        int c1 = 0, c2 = 0;
        for (int k = 1; k < n; k++) {
            add_sum(c1, _mul(fact[k], A[n - k]));
        }
        for (int k = 3; k < n; k++) {
            add_sum(c2, _mul(B[n][k], F[k]));
        }
        add_sub(F[n], _mul(2, c1));
        add_sub(F[n], c2);
    }
    F[2] = 2;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int tt;
    cin >> tt >> mod;

    precalc();

    for (int ti = 0; ti < tt; ti++) {
        int n;
        cin >> n;
        cout << F[n] << "\n";
    }

    return 0;
}