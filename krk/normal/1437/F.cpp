#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 5005;

int fac[Maxn], ifac[Maxn];
int n;
int a[Maxn];
vector <int> un;
int cnt[Maxn];
int dp[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int main()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 1; i <= n; i++) {
        int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
        cnt[ind]++;
    }
    if (cnt[int(un.size()) - 1] > 1) { printf("0\n"); return 0; }
    dp[int(un.size()) - 1] = 1;
    int all = 1;
    for (int i = int(un.size()) - 2; i >= 0; i--) {
        for (int j = i + 1; j < un.size(); j++) if (dp[j]) {
                int ways = dp[j]; dp[j] = 0;
                if (2 * un[i] <= un[j]) {
                    dp[j] = (dp[j] + ll(ways) * fac[all + cnt[i] - 1] % mod * ifac[all - 1]) % mod;
                    dp[i] = (dp[i] + ll(ways) * cnt[i] % mod * fac[all + cnt[i] - 2] % mod * ifac[all - 1]) % mod;
                } else if (2 * un[i] <= un.back())
                    dp[j] = (dp[j] + ll(ways) * fac[all + cnt[i] - 2] % mod * ifac[all - 2]) % mod;
            }
        all += cnt[i];
    }
    int res = 0;
    for (int i = 0; i < un.size(); i++)
        res = (res + dp[i]) % mod;
    printf("%d\n", res);
    return 0;
}