#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int n, k;
int dp[Maxn];
ll res;
int sav[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    ll sum = 0;
    dp[0] = 1;
    for (int j = k; sum <= n; j++) {
        for (int i = 0; i < j && sum + i <= n; i++) {
            int cur = 0;
            for (int z = sum + i; z <= n; z += j) {
                int mem = dp[z];
                dp[z] = cur;
                sav[z] = (sav[z] + mem) % mod;
                cur = (cur + mem) % mod;
            }
        }
        sum += j;
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", sav[i], i + 1 <= n? ' ': '\n');
    return 0;
}