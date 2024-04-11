#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100001;
const int mod = 1000000007;

vector <int> dvs[Maxn];
int n;
int dp[Maxn];
int vals[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            dvs[j].push_back(i);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int sam = n / i;
        vals[dvs[i].size() - 1] = sam;
        int res = n;
        for (int j = int(dvs[i].size()) - 2; j >= 0; j--) {
            vals[j] = n / dvs[i][j];
            for (int k = j + 1; k < dvs[i].size(); k++)
                if (dvs[i][k] % dvs[i][j] == 0)
                    vals[j] = (vals[j] - vals[k] + mod) % mod;
            res = (res + ll(vals[j]) * dp[dvs[i][j]]) % mod;
        }
        dp[i] = ll(res) * Inv(n - sam) % mod;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = (res + dp[i]) % mod;
    res = ll(res) * Inv(n) % mod;
    printf("%d\n", res);
    return 0;
}