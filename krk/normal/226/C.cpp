#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 2;

int mod;
ll l, r, k;
vector <ll> V;
ll res;

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
                    c.m[i][j] = (c.m[i][j] + ll(m[i][k]) * b.m[k][j]) % mod;
        return c;
    }
};

void getAll(ll x)
{
    for (ll i = 1, j; i <= x; i = j + 1) {
         j = x / (x / i);
         V.push_back(j);
    }
}

int main()
{
    scanf("%d %I64d %I64d %I64d", &mod, &l, &r, &k);
    getAll(r);
    getAll(l - 1);
    for (int i = 0; i < V.size(); i++)
        if (r / V[i] - (l - 1) / V[i] >= k)
            res = max(res, V[i]);
    matrix R(1), A;
    A.m[0][0] = A.m[0][1] = A.m[1][0] = 1;
    while (res) {
        if (res & 1) R = R * A;
        res >>= 1; A = A * A;
    }
    cout << R.m[0][1] << endl;
    return 0;
}