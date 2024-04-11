#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int inv2 = (mod + 1) / 2;
const int Maxm = 17;
const int Maxd = 4;

struct matrix {
    int m[Maxm][Maxm];
    matrix(int diag = 0) {
        for (int i = 0; i < Maxm; i++)
            for (int j = 0; j < Maxm; j++)
                m[i][j] = (i == j) * diag;
    }
    matrix operator*(const matrix &b) const {
        matrix c;
        for (int i = 0; i < Maxm; i++)
            for (int j = 0; j < Maxm; j++)
                for (int k = 0; k < Maxm; k++)
                    c.m[i][j] = (c.m[i][j] + ll(m[i][k]) * b.m[k][j]) % mod;
        return c;
    }
};

int L, R;

int Get(int X)
{
    if (X <= 0) return 0;
    if (X == 1) return 4;
    matrix R(1), A;
    int col[Maxm] = {0};
    col[Maxm - 1] = 4;
    for (int a = 0; a < Maxd; a++)
        for (int b = 0; b < Maxd; b++) if (a / 2 != b / 2) {
            col[Maxd * a + b]++;
            col[Maxm - 1]++;
        }
    for (int a = 0; a < Maxd; a++)
        for (int b = 0; b < Maxd; b++)
            for (int c = 0; c < Maxd; c++)
                if (b / 2 != c / 2 && !(a == 3 && b == 0 && c == 2 ||
                                        a == 2 && b == 0 && c == 3)) {
                    A.m[Maxd * b + c][Maxd * a + b]++;
                    A.m[Maxm - 1][Maxd * a + b]++;
                }
    A.m[Maxm - 1][Maxm - 1]++;
    X -= 2;
    while (X) {
        if (X & 1) R = R * A;
        X >>= 1; A = A * A;
    }
    int res = 0;
    for (int j = 0; j < Maxm; j++)
        res = (res + ll(R.m[Maxm - 1][j]) * col[j]) % mod;
    return res;
}

int Solve(int X)
{
    return ll(Get(X) + Get((X + 1) / 2)) % mod * inv2 % mod;
}

int main()
{
    scanf("%d %d", &L, &R);
    printf("%d\n", (Solve(R) - Solve(L - 1) + mod) % mod);
    return 0;
}