#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3;
const int Inf = 1000000000;

int n;
int dp[1 << Maxn];

int main()
{
    fill(dp, dp + (1 << Maxn), Inf);
    dp[0] = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int c; string s; cin >> c >> s;
        int mask = 0;
        for (int j = 0; j < s.length(); j++)
            mask |= 1 << int(s[j] - 'A');
        for (int j = 0; j < 1 << Maxn; j++)
            dp[j | mask] = min(dp[j | mask], dp[j] + c);
    }
    if (dp[(1 << Maxn) - 1] >= Inf) printf("-1\n");
    else printf("%d\n", dp[(1 << Maxn) - 1]);
    return 0;
}