#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int Maxn = 200005;

char s[Maxn];
int slen;
int dp[Maxn];

int main()
{
    scanf("%s", s);
    slen = strlen(s);
    for (int i = 0; i < slen; i++)
        if (s[i] == 'w' || s[i] == 'm') {
            printf("0\n"); return 0;
        }
    dp[0] = 1;
    for (int i = 0; i < slen; i++) {
        dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
        if (i + 1 < slen && s[i] == s[i + 1] && (s[i] == 'u' || s[i] == 'n'))
            dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
    }
    printf("%d\n", dp[slen]);
    return 0;
}