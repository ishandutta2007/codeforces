#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 505;
int const ITER = 65;

int n, m;
int G0[N][N];
int G1[N][N];

struct Matrix {
    bool mat[N][N];
    bitset< N > str[N];
    bitset< N > col[N];
    Matrix() {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                mat[i][j] = 0;
                str[i][j] = 0;
                col[i][j] = 0;
            }
        }
    }
    Matrix & operator = (Matrix const & tmp) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                mat[i][j] = tmp.mat[i][j];
                str[i][j] = tmp.str[i][j];
                col[i][j] = tmp.col[i][j];
            }
        }
        return *this;
    }
} A[ITER], B[ITER];

Matrix mul(Matrix const & m1, Matrix const & m2) {
    Matrix res;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            res.mat[i][j] = (m1.col[j] & m2.str[i]).any();
            res.str[i][j] = res.mat[i][j];
            res.col[j][i] = res.mat[i][j];
        }
    }
    return res;
}

int main() {

    scanf("%d %d", &n, &m);

    for(int u, v, t, i = 0;i < m;i++) {
        scanf("%d %d %d", &u, &v, &t);
        u--, v--;
        if(t == 0) {
            G0[v][u] = 1;
        }else {
            G1[v][u] = 1;
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            A[0].mat[i][j] = G0[i][j];
            A[0].str[i][j] = G0[i][j];
            A[0].col[j][i] = G0[i][j];

            B[0].mat[i][j] = G1[i][j];
            B[0].str[i][j] = G1[i][j];
            B[0].col[j][i] = G1[i][j];
        }
    }

    for(int it = 1;it < ITER;it++) {
        A[it] = mul(A[it - 1], B[it - 1]);
        B[it] = mul(B[it - 1], A[it - 1]);
    }

    ll res = 0;

    Matrix cur;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cur.mat[i][i] = 1;
            cur.str[i][i] = 1;
            cur.col[i][i] = 1;
        }
    }

    for(int type = 0, it = 60;it >= 0;it--) {
        Matrix tmp = mul(cur, (type == 0 ? A[it] : B[it]) );
        if(tmp.col[0].any()) {
            res += (1ll << it);
            cur = tmp;
            type ^= 1;
        }
    }

    if(res > inf64) {
        cout << -1 << "\n";
    }else {
        cout << res << "\n";
    }

    return 0;
}