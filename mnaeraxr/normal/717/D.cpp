#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

struct matrix{
    int n;
    vector<vector<double>> M;

    matrix(int n) : n(n){
        M = vector<vector<double>>(n, vector<double>(n));
    }

    matrix operator *(const matrix &A) const{
        matrix ans(n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    ans.M[i][j] += M[i][k] * A.M[k][j];

        return ans;
    }
};

matrix identity(int n){
    matrix M(n);
    for (int i = 0; i < n; ++i)
        M.M[i][i] = 1.0;
    return M;
}

matrix fast_exp(matrix M, int n){
    if (n == 0) return identity(M.n);
    if (n & 1) return M * fast_exp(M, n - 1);
    else return fast_exp(M * M, n / 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int m, n;
    cin >> m >> n;
    vector<double> prob(128);

    for (int i = 0; i <= n; ++i)
        cin >> prob[i];

    matrix base(128);

    for (int i = 0; i < 128; ++i)
        for (int j = 0; j < 128; ++j){
            int x = i ^ j;
            base.M[i][j] = prob[x];
        }


    matrix final = fast_exp(base, m);

    cout.precision(17);
    cout << fixed << 1.0 - final.M[0][0] << endl;

    return 0;
}