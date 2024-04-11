#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxd = 14;

struct matrix {
    int m[Maxd][Maxd];
    matrix(int diag = 0) {
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                m[i][j] = (i == j) * diag;
    }
    matrix operator*(const matrix &b) const {
        matrix c;
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                for (int k = 0; k < Maxd; k++)
                    c.m[i][j] = (ll(c.m[i][j]) + ll(m[i][k]) * b.m[k][j]) % (mod - 1);
        return c;
    }
};

ll n;
int f1, f2, f3, c;
int col[Maxd];

int toPower(int a, int pw)
{
    int res = 1;
    while (pw) {
        if (pw & 1) res = ll(res) * a % mod;
        pw >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int getRow(const matrix &R, int row)
{
    int res = 0;
    for (int j = 0; j < Maxd; j++)
        res = (res + ll(R.m[row][j]) * col[j]) % (mod - 1);
    return res;
}

int main()
{
    cin >> n >> f1 >> f2 >> f3 >> c;
    matrix R(1), A;
    A.m[0][0] = A.m[0][3] = A.m[0][6] = 1;
    A.m[1][1] = A.m[1][4] = A.m[1][7] = 1;
    A.m[2][2] = A.m[2][5] = A.m[2][8] = 1;
    A.m[3][0] = 1;
    A.m[4][1] = 1;
    A.m[5][2] = 1;
    A.m[6][3] = 1;
    A.m[7][4] = 1;
    A.m[8][5] = 1;
    A.m[9][9] = A.m[9][10] = A.m[9][11] = A.m[9][12] = 1; A.m[9][13] = 2;
    A.m[10][9] = 1;
    A.m[11][10] = 1;
    A.m[12][12] = 1; A.m[12][13] = 2;
    A.m[13][13] = 1;
    col[2] = col[4] = col[6] = col[13] = 1;
    n -= 3;
    while (n) {
        if (n & 1ll) R = R * A;
        n >>= 1ll; A = A * A;
    }
    int res = toPower(f1, getRow(R, 0));
    res = ll(res) * toPower(f2, getRow(R, 1)) % mod;
    res = ll(res) * toPower(f3, getRow(R, 2)) % mod;
    res = ll(res) * toPower(c, getRow(R, 9)) % mod;
    printf("%d\n", res);
    return 0;
}