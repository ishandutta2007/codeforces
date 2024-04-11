#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 101;
const int Maxd = 1001;
const ll mod = 1000000007;

ll m, A[Maxn], B[Maxn], C[Maxd][Maxd];
ll sum;
ll ways[Maxn][Maxd], res;

int main()
{
    C[0][0] = 1;
    for (int i = 1; i < Maxd; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
    cin >> m;
    for (int i = 0; i < m; i++) { cin >> A[i]; sum += A[i]; }
    for (int i = 0; i < m; i++) cin >> B[i];
    ways[0][0] = 1;
    for (ll i = 1; i <= m; i++)
       for (ll j = 0; j < Maxd; j++)
          for (ll l = max(0LL, j - A[i-1]); l <= B[i-1] - A[i-1] + j && l < Maxd; l++)
             ways[i][j] = (ways[i][j] + C[A[i-1]+l][A[i-1]+l-j] * ways[i-1][l]) % mod;
    res = ways[m][0];
    for (int i = 0; i < m; i++) {
        res = (res * C[sum][A[i]]) % mod;
        sum -= A[i];
    }
    cout << res << endl;
    return 0;
}