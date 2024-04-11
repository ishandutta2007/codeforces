#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const int mod = 1000000007;

struct matrix {
    int m[Maxn][Maxn];
    matrix(int diag = 0) {
        for (int i = 0; i < Maxn; i++)
            for (int j = 0; j < Maxn; j++)
                m[i][j] = (i == j) * diag;
    }
    matrix operator *(const matrix &b) const {
        matrix c;
        for (int i = 0; i < Maxn; i++)
            for (int j = 0; j < Maxn; j++)
                for (int l = 0; l < Maxn; l++)
                    c.m[i][j] = (ll(c.m[i][j]) + ll(m[i][l]) * b.m[l][j]) % mod;
        return c;
    }
};

ll n;
int m;

int main()
{
    cin >> n >> m;
    matrix R(1), A;
    A.m[0][0] = A.m[0][m - 1] = 1;
    for (int i = 1; i < m; i++)
        A.m[i][i - 1] = 1;
    while (n) {
        if (n & 1) R = R * A;
        n >>= 1; A = A * A;
    }
    printf("%d\n", R.m[0][0]);
    return 0;
}