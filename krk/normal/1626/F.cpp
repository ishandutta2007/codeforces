#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 720720;
const int mod = 998244353;
const int Maxk = 19;

int n, a, x, y, k, m;
int sum;
int S[Maxk], C[Maxk][Maxn];
int P[Maxk];
int res;

int main()
{
    scanf("%d %d %d %d %d %d", &n, &a, &x, &y, &k, &m);
    for (int i = 0; i < n; i++) {
        S[1] = (S[1] + a) % mod;
        C[1][a % Maxn]++;
        a = (ll(a) * x + ll(y)) % m;
    }
    P[0] = 1;
    for (int i = 1; i <= k; i++)
        P[i] = ll(P[i - 1]) * n % mod;
    for (int i = 1; i <= k; i++) {
        S[i + 1] = ll(S[i]) * n % mod;
        res = (res + ll(S[i]) * P[k - i]) % mod;
        for (int j = 0; j < Maxn; j++) {
            C[i + 1][j] = (C[i + 1][j] + ll(C[i][j]) * (n - 1)) % mod;
            int nj = j / i * i;
            S[i + 1] = (S[i + 1] - ll(j - nj) * C[i][j] % mod + mod) % mod;
            C[i + 1][nj] = (C[i + 1][nj] + C[i][j]) % mod;
        }
    }
    cout << res << endl;
    return 0;
}