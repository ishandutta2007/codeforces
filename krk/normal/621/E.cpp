#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxd = 102;
const int mod = 1000000007;
const int Maxc = 10;

int n, b, k, x;
int freq[Maxc];

struct matrix {
    int m[Maxd][Maxd];
    matrix(int diag = 0) {
        fill((int*)m, (int*)m + Maxd * Maxd, 0);
        if (diag)
            for (int i = 0; i < Maxd; i++)
                m[i][i] = 1;
    }
    matrix operator *(const matrix &b) const {
        matrix c;
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                for (int l = 0; l < Maxd; l++)
                    c.m[i][j] = (c.m[i][j] + ll(m[i][l]) * b.m[l][j]) % mod;
        return c;
    }
};

int main()
{
    scanf("%d %d %d %d", &n, &b, &k, &x);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        freq[a]++;
    }
    matrix R(1), A;
    for (int i = 0; i < Maxc; i++)
        for (int j = 0; j < x; j++) {
            int nw = (10 * j + i) % x;
            A.m[nw][j] += freq[i];
        }
    while (b) {
        if (b & 1) R = R * A;
        b >>= 1; A = A * A;
    }
    printf("%d\n", R.m[k][0]);
    return 0;
}