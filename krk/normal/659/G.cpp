#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int mod = 1000000007;

int n;
int h[Maxn];
int dp[Maxn];
int res;

int min(int a, int b, int c) { return min(min(a, b), c); }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);
    for (int i = 0; i < n; i++) {
        if (i) {
            res = (res + ll(dp[i - 1]) * ll(min(h[i - 1], h[i]) - 1)) % mod;
            if (i + 1 < n)
                dp[i] = (dp[i] + ll(dp[i - 1]) * ll(min(h[i - 1], h[i], h[i + 1]) - 1)) % mod;
        }
        res = (res + h[i] - 1) % mod;
        if (i + 1 < n)
            dp[i] = (dp[i] + min(h[i], h[i + 1]) - 1) % mod;
    }
    printf("%d\n", res);
	return 0;
}