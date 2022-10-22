#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int n, q;
int sum[Maxn];
char str[Maxn];
int my[Maxn];

int main()
{
    scanf("%d %d", &n, &q);
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        sum[i] = (sum[i - 1] + cur) % mod;
        cur = 2 * cur % mod;
    }
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
        my[i] = my[i - 1] + (str[i] == '1');
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        int ones = my[r] - my[l - 1];
        int zers = r - l + 1 - ones;
        int res = (ll(sum[ones]) + ll(sum[ones]) * sum[zers]) % mod;
        printf("%d\n", res);
    }
    return 0;
}