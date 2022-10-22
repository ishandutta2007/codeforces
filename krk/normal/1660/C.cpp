#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxl = 26;

int T;
char str[Maxn];
int prv[Maxn];
int nxt[Maxn];
int dp[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str); slen = strlen(str);
        for (int i = 0; i < Maxl; i++)
            prv[i] = -1;
        for (int i = 0; i < slen; i++) {
            int ch = str[i] - 'a';
            if (prv[ch] != -1) 
                nxt[prv[ch]] = i;
            nxt[i] = slen;
            prv[ch] = i;
        }
        dp[slen] = 0;
        for (int i = slen - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            if (nxt[i] < slen) dp[i] = max(dp[i], 2 + dp[nxt[i] + 1]);
        }
        printf("%d\n", slen - dp[0]);
    }
    return 0;
}