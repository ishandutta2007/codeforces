#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxm = 100005;
const ll Inf = 1000000000000000000ll;
const int Maxn = 1000005;

bool prime[Maxm];
vector <int> pr;
int n, a, b;
int val[Maxn];
set <int> my;
ll dp[Maxn][3], dp2[Maxn][2];
ll res = Inf;

void Get(int x)
{
    for (int i = 0; i < pr.size() && pr[i] <= x / pr[i]; i++)
        if (x % pr[i] == 0) {
            my.insert(pr[i]);
            while (x % pr[i] == 0) x /= pr[i];
        }
    if (x > 1) my.insert(x);
}

ll costMod(int x, int P)
{
    if (x % P == 0) return 0ll;
    else if ((x - 1) % P == 0 || (x + 1) % P == 0) return b;
    else return Inf;
}

int main()
{
    fill(prime + 2, prime + Maxm, true);
    for (int i = 2; i < Maxm; i++) if (prime[i]) {
        pr.push_back(i);
        for (int j = i + i; j < Maxm; j += i)
            prime[j] = false;
    }
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);
    if (n == 1) { printf("0\n"); return 0; }
    for (int i = -1; i <= 1; i++) {
        Get(val[0] + i); Get(val[n - 1] + i);
    }
    for (set <int>::iterator it = my.begin(); it != my.end(); it++) {
        int P = *it;
        fill((ll*)dp, (ll*)dp + Maxn * 3, Inf);
        fill((ll*)dp2, (ll*)dp2 + Maxn * 2, Inf);
        dp[1][0] = costMod(val[0], P);
        dp2[1][0] = a;
        for (int i = 1; i < n; i++) {
            // 0
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + costMod(val[i], P));
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + a);
            // 1
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a);
            dp[i + 1][2] = min(dp[i + 1][2], dp[i][1] + costMod(val[i], P));
            // 2
            dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + costMod(val[i], P));

            // 0
            dp2[i + 1][0] = min(dp2[i + 1][0], dp2[i][0] + a);
            dp2[i + 1][1] = min(dp2[i + 1][1], dp2[i][0] + costMod(val[i], P));
            // 1
            dp2[i + 1][1] = min(dp2[i + 1][1], dp2[i][1] + costMod(val[i], P));
        }
        res = min(res, min(dp[n][0], min(dp[n][1], dp[n][2])));
        res = min(res, min(dp2[n - 1][0], dp2[n - 1][1]) + costMod(val[n - 1], P));
    }
    printf("%I64d\n", res);
    return 0;
}