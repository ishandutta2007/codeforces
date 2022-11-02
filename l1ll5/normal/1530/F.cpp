#include<bits/stdc++.h>
using namespace std;
const int N = 30 + 5;
constexpr int mod = 31607;
using LL = long long;
int n;
int a[N][N];
int Qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = 1ll * ret * a % mod;
        }
        b >>= 1;
        a = 1ll * a * a % mod;
    }
    return ret;
}
int Inv(int x) {
    return Qpow(x, mod - 2);
}
int b[N][N];
int A[(1 << 23) + 5];
int S[30][(1 << 21) + 5];
int cp(int i, int m) {
    return  (i >> (m - 1));
}
void fwt(int p) {
    int m = n + 2;
    int s = (1 << n) - 1;
    for (int i = 0; i < (1 << m); i += 1) {
        int tp = cp(i, m);
        int k;
        if (tp & 1) {
            k = (i & s)
                | (((i >> n) & 1) << p)
                | (1 << (n - 1 - p));
        }
        else {
            k = (i & s)
                | (((i >> n) & 1) << p);
        }
        (A[i] *= S[p][k]) %= mod;
    }
}
void doit(int p) {
    for (int i = 0; i < (1 << n); i += 1) {
        int cur = 1;
        for (int j = 0; j < n; j += 1) {
            if ((i >> j) & 1) cur = cur * a[p][j] % mod;
        }
        S[p][i] = cur;
    }
}
void ft(int i, int j) {
    A[j] -= A[j | (1 << i)],
        A[j] += mod,
        A[j] %= mod;
}
void solve() {
    int m = n + 2;
    for (int i = 0; i < m; i += 1)
        for (int j = 0; j < (1 << m); j += 1)
            if (!((j >> i) & 1))
                ft(i, j);

}
int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        cin >> n;
        int iv = Inv(10000);
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < n; j += 1)
                cin >> a[i][j], a[i][j] = a[i][j] * iv % mod, b[i][j] = (1 - a[i][j] + mod) % mod;
        }
        for (int i = 0; i < (1 << (n + 2)); i += 1) A[i] = 1;
        for (int p = 0; p < n; p += 1) {
            doit(p);
            int one = S[p][(1 << n) - 1];
            for (int i = 0; i < (1 << n); i += 1)
                S[p][i] = (S[p][i] - one + mod) % mod;
            fwt(p);
        }
        solve();
        cout << (1 - A[0] + mod) % mod;
    }

}
/*

*/