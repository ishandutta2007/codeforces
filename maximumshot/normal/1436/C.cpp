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

int slow(int n, int x, int pos) {
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = i + 1;
    int res = 0;
    do {
        if (p[pos] != x)
            continue;
        int le = 0, ri = n, mid;
        while (le < ri) {
            mid = (le + ri) / 2;
            if (p[mid] <= x)
                le = mid + 1;
            else
                ri = mid;
        }
        if (le > 0 && p[le - 1] == x)
            res++;
    } while (next_permutation(p.begin(), p.end()));
    return res;
}

int fast(int n, int x, int pos) {
    vector<vector<int>> C(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = _sum(C[i - 1][j - 1], C[i - 1][j]);
        }
    }
    vector<int> F(n + 1);
    F[0] = 1;
    for (int i = 1; i <= n; i++)
        F[i] = _mul(F[i - 1], i);

    vector<int> lt(n), gt(n);

    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
//        cout << "[" << l << ", " << r << "), mid = " << mid << "\n";
        if (pos >= mid) {
            l = mid + 1;
            lt[mid] = 1;
        } else {
            r = mid;
            gt[mid] = 1;
        }
    }

//    for (int i = 0; i < n; i++) {
//        if (i == pos)
//            continue;
//        if (lt[i])
//            cout << i << " ";
//    }
//    cout << "\n";
//    for (int i = 0; i < n; i++) {
//        if (i == pos)
//            continue;
//        if (gt[i])
//            cout << i << " ";
//    }
//    cout << "\n";

    int clt = 0, cgt = 0;

    for (int i = 0; i < n; i++) {
        if (i == pos)
            continue;
        if (lt[i])
            clt++;
        if (gt[i])
            cgt++;
    }

    if (clt > x - 1 || cgt > n - x) {
        return 0;
    }

    return _mul(_mul(C[x - 1][clt], C[n - x][cgt]), _mul(F[n - 1 - clt - cgt], _mul(F[clt], F[cgt])));
}

void test() {
    const int MAXN = 4;
    mt19937 rnd(42);

    int n, x, pos;

    while (1) {
        n = rnd() % MAXN + 1;
        x = rnd() % n + 1;
        pos = rnd() % n;

        int sl = slow(n, x, pos);
        int fs = fast(n, x, pos);

        if (sl == fs)
            cout << "OK(" << fs << ")\n";
        else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";

            cout << n << " " << x << " " << pos << "\n";
            break;
        }
    }
}

void work() {
    int n, x, pos;
    cin >> n >> x >> pos;
    cout << fast(n, x, pos) << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}