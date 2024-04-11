#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 998244353;
const int Maxd = 2;

struct matrix {
    int m[Maxd][Maxd];
    matrix(int diag = 0) {
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                m[i][j] = (i == j) * diag;
    }
    matrix operator*(const matrix &oth) const {
        matrix res;
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                for (int k = 0; k < Maxd; k++)
                    res.m[i][j] = (res.m[i][j] + ll(m[i][k]) * oth.m[k][j]) % mod;
        return res;
    }
};

int n, m, L, R;

ii Get(ll hm)
{
    matrix res(1);
    matrix A;
    int ev = (R - L + 1 + int(L % 2 == 0)) / 2;
    int od = (R - L + 1 + int(L % 2 != 0)) / 2;
    A.m[0][0] = A.m[1][1] = ev;
    A.m[0][1] = A.m[1][0] = od;
    while (hm) {
        if (hm & 1ll) res = res * A;
        hm >>= 1ll; A = A * A;
    }
    return ii(res.m[0][0], res.m[1][0]);
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &L, &R);
    if (L > R) { printf("0\n"); return 0; }
    ii got = Get(ll(n) * m);
    int res = ll(n) * m % 2? (got.first + got.second) % mod: got.first;
    cout << res << endl;
    return 0;
}