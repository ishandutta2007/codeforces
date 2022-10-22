#include <iostream>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int mod = 1000000007;

int n, m, k;
int C[Maxn][Maxn];

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    cin >> n >> m >> k;
    if (2 * k > n - 1 || 2 * k > m - 1) cout << "0\n";
    else cout << ll(C[n - 1][2 * k]) * ll(C[m - 1][2 * k]) % ll(mod) << endl;
    return 0;
}