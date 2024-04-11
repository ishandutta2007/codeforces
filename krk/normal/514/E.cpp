#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxd = 101;
const int mod = 1000000007;

struct matrix {
    int x[Maxd][Maxd];
    matrix(int diag = 0) {
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                x[i][j] = (i == j) * diag;
    }
    matrix operator*(const matrix &b) const {
        matrix c;
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                for (int k = 0; k < Maxd; k++)
                    c.x[i][j] = (c.x[i][j] + ll(x[i][k]) * b.x[k][j]) % mod;
        return c;
    }
};

int n, x;
int f[Maxd];
matrix a, r(1);

int main()
{
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        f[a]++;
    }
    a.x[0][0] = 1;
    for (int j = 1; j < Maxd; j++)
        a.x[0][j] = a.x[1][j] = f[j];
    for (int i = 2; i < Maxd; i++)
        a.x[i][i - 1] = 1;
    while (x) {
        if (x & 1) r = r * a;
        x >>= 1; a = a * a;
    }
    printf("%d\n", (r.x[0][0] + r.x[0][1]) % mod);
    return 0;
}