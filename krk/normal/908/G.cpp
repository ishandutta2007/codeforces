#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 10;
const int Maxn = 705;
const int mod = 1000000007;

int C[Maxn][Maxn];
int pw[Maxd + 1][Maxn];
int ones[Maxn];
string X;
int res;

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    for (int i = 0; i <= Maxd; i++) {
        pw[i][0] = 1;
        for (int j = 1; j < Maxn; j++)
            pw[i][j] = ll(pw[i][j - 1]) * i % mod;
    }
    for (int i = 1; i < Maxn; i++)
        ones[i] = (10ll * ones[i - 1] + 1ll) % mod;
    cin >> X;
    int n = X.length();
    for (int d = 1; d < Maxd; d++) {
        int multa = d, multb = Maxd - 1 - d;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            int dig = X[i] - '0';
            if (dig) {
                int small = min(dig, d);
                int my = d < dig;
                int big = max(0, dig - 1 - d);
                int j = n - i - 1;
                for (int addb = 0; addb <= j; addb++) {
                    int adda = j - addb;
                    // me and bigger
                    int ways = ll(C[j][adda]) * pw[multa][adda] % mod * pw[multb + 1][addb] % mod * d % mod;
                    int alla = a + adda;
                    int allb = n - alla;
                    if (allb >= 1) res = (res + ll(ways) * small % mod * ones[allb - 1]) % mod;
                    res = (res + ll(ways) * (my + big) % mod * ones[allb]) % mod;
                    // only bigger
                    ways = ll(C[j][adda]) * pw[multa + 1][adda] % mod * pw[multb][addb] % mod * d % mod;
                    allb = b + addb;
                    alla = n - allb;
                    res = (res - ll(ways) * big % mod * ones[allb + 1] % mod + mod) % mod;
                    res = (res - ll(ways) * (small + my) % mod * ones[allb] % mod + mod) % mod;
                }
            }
            if (dig < d) a++;
            else if (dig > d) b++;
        }
        // me and bigger
        int me = n - a - b;
        res = (res + ll(d) * ones[me + b]) % mod;
        // only bigger
        res = (res - ll(d) * ones[b] % mod + mod) % mod;
    }
    cout << res << endl;
    return 0;
}