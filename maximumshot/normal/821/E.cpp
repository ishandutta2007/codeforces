#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int Sum(int a, int b) {
    return (a + b) % mod;
}

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline void Add(int & x, int y) {
    x = Sum(x, y);
}

int const C = 16;

struct Matrix {
    int n, m;
    int a[C][C];
    Matrix() : n(0), m(0) { }
    Matrix & operator = (Matrix const & other) {
        if(this == &other) return *this;
        n = other.n;
        m = other.m;
        for(int i = 0;i < C;i++) {
            for(int j = 0;j < C;j++) {
                a[i][j] = other.a[i][j];
            }
        }
        return *this;
    }
};

Matrix Mul(Matrix const & a, Matrix const & b) {
    Matrix res;
    res.n = a.n;
    res.m = b.m;
    for(int i = 0;i < res.n;i++) {
        for(int j = 0;j < res.m;j++) {
            res.a[i][j] = 0;
            for(int t = 0;t < a.m;t++) {
                Add(res.a[i][j], Mul(a.a[i][t], b.a[t][j]));
            }
        }
    }
    return res;
}

int const N = 105;

int n;
ll k;
pll seg[N];
ll Y[N];

Matrix buildSqr(int sz) {
    Matrix res;
    res.n = res.m = sz;
    for(int i = 0;i < sz;i++) {
        for(int j = 0;j < sz;j++) {
            res.a[i][j] = 0;
        }
    }
    for(int y = 0;y < sz;y++) {
        if(y > 0) {
            res.a[y][y - 1] = 1 % mod;
        }
        res.a[y][y] = 1 % mod;
        if(y + 1 < sz) {
            res.a[y][y + 1] = 1 % mod;
        }
    }
    return res;
}

Matrix buildStart(int sz) {
    Matrix res;
    res.n = sz;
    res.m = 1;
    for(int i = 0;i < sz;i++) {
        res.a[i][0] = 0;
    }
    res.a[0][0] = 1 % mod;
    return res;
}

Matrix buildE(int sz) {
    Matrix res;
    res.n = res.m = sz;
    for(int i = 0;i < sz;i++) {
        for(int j = 0;j < sz;j++) {
            if(i == j) {
                res.a[i][j] = 1 % mod;
            }else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}

Matrix binpow(Matrix sq, ll pw) {
    if(pw == 0) {
        return buildE(sq.n);
    }else {
        Matrix tmp = binpow(sq, pw / 2);
        tmp = Mul(tmp, tmp);
        if(pw % 2) {
            tmp = Mul(tmp, sq);
        }
        return tmp;
    }
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> k;

    for(int i = 0;i < n;i++) {
        cin >> seg[i].first >> seg[i].second >> Y[i];
    }

    Matrix cl = buildStart(Y[0] + 1);

    for(int iter = 0;iter < n;iter++) {
        Matrix sq = buildSqr(Y[iter] + 1);
        if(iter + 1 < n) {
            sq = binpow(sq, seg[iter].second - seg[iter].first);
            cl = Mul(sq, cl);
            if(Y[iter] <= Y[iter + 1]) {
                cl.n = Y[iter + 1] + 1;
                for(int i = Y[iter] + 1;i <= Y[iter + 1];i++){
                    cl.a[i][0] = 0;
                }
            }else {
                cl.n = Y[iter + 1];
            }
        }else {
            sq = binpow(sq, min(k, seg[iter].second) - seg[iter].first);
            cl = Mul(sq, cl);
            printf("%d\n", cl.a[0][0]);
            return 0;
        }
    }

    return 0;
}