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

const int N = 3605;

int del_row[N];
int del_col[N];
int C[N][N];
int row[N][N], col[N][N];
int fact[N];

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = _mul(fact[i - 1], i);
    }
    for (int i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = _sum(C[i - 1][j - 1], C[i - 1][j]);
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();

    int h, w, n;

    cin >> h >> w >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            del_row[x] = 1;
            del_col[y] = 1;
        }
    }

    int cv1 = 0;
    int cv2 = 0;

    for (int i = 0; i < h; i++) {
        if (!del_row[i]) cv1++;
//        cout << del_row[i];
    }
//    cout << "\n";

    for (int i = 0; i < w; i++) {
        if (!del_col[i]) cv2++;
//        cout << del_col[i];
    }
//    cout << "\n";

    row[0][0] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j <= h; j++) {
            row[i][j] = row[i - 1][j];
        }
        if (del_row[i - 1]) continue;
        if (i >= 2 && !del_row[i - 1] && !del_row[i - 2]) {
            for (int j = 1; j <= h; j++) {
                _inc(row[i][j], row[i - 2][j - 1]);
            }
        }
    }

    col[0][0] = 1;
    for (int i = 1; i <= w; i++) {
        for (int j = 0; j <= w; j++) {
            col[i][j] = col[i - 1][j];
        }
        if (del_col[i - 1]) continue;
        if (i >= 2 && !del_col[i - 1] && !del_col[i - 2]) {
            for (int j = 1; j <= w; j++) {
                _inc(col[i][j], col[i - 2][j - 1]);
            }
        }
    }

    int res = 0;

//    cout << cv1 << " " << cv2 << "\n";

    for (int d1 = 0; 2 * d1 <= cv1; d1++) {
        for (int d2 = 0; 2 * d2 <= cv2; d2++) {
            int m1 = C[cv1 - 2 * d1][d2];
            int m2 = C[cv2 - 2 * d2][d1];
            int m3 = _mul(row[h][d1], fact[d1]);
            int m4 = _mul(col[w][d2], fact[d2]);
            _inc(res, _mul(_mul(m1, m2), _mul(m3, m4)));
//            cout << d1 << " " << d2 << " " << m1 << " " << m2 << " " << m3 << " " << m4 << "\n";
        }
    }

    cout << res << "\n";

    return 0;
}