#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 50;
const int maxl = 20;

int n, m;

char C[maxn][maxl + 1];
int64 ND[1 << maxl];
int64 T[1 << maxl];
int64 R[maxn][maxl];
int64 total[1 << maxl];
double E[1 << maxl];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> C[i];

    m = strlen(C[0]);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            for (int k = 0; k < n; ++k){
                if (i == k) continue;
                if (C[i][j] == C[k][j])
                    R[i][j] |= 1LL << k;
            }
        }
    }

    T[0] = ND[0] = n == 1 ? 0 : ((1LL << n) - 1);

    for (int i = 0; i < n; ++i){
        int64 I = 1LL << i;
        for (int j = 1; j < (1 << m); ++j){
            int b = __lg(j);
            T[j] = T[j ^ (1 << b)] & R[i][b];
            if (T[j]) ND[j] |= I;
        }
    }

    for (int i = (1 << m) - 2; ~i; --i){
        if (!ND[i]) continue;

        double t = 1.0 / (m - __builtin_popcount(i));
        total[i] = __builtin_popcountll(ND[i]);

        for (int j = 0; j < m; ++j){
            if (i >> j & 1) continue;

            int nx = i ^ (1 << j);
            E[i] += E[nx] * total[nx] / total[i];
        }

        E[i] = 1.0 + t * E[i];
    }

    cout.precision(17);
    cout << fixed << E[0] << endl;

    return 0;
}