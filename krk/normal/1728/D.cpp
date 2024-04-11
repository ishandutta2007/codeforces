#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
char str[Maxn];
int slen;
bool dp[Maxn][Maxn];

int Comp(char a, char b)
{
    if (a != b) return a < b? 1: -1;
    return 0;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        for (int i = 0; i + 1 < slen; i++)
            dp[i][i + 1] = str[i] == str[i + 1]? 0: 1;
        for (int l = 4; l <= slen; l += 2)
            for (int i = 0, j = l - 1; j < slen; i++, j++) {
                int w11 = dp[i + 2][j] == 0? Comp(str[i], str[i + 1]): dp[i + 2][j];
                int w12 = dp[i + 1][j - 1] == 0? Comp(str[i], str[j]): dp[i + 1][j - 1];
                int w21 = dp[i + 1][j - 1] == 0? Comp(str[j], str[i]): dp[i + 1][j - 1];
                int w22 = dp[i][j - 2] == 0? Comp(str[j], str[j - 1]): dp[i][j - 2];
                dp[i][j] = max(min(w11, w12), min(w21, w22));
            }
        if (dp[0][slen - 1] == 1) printf("Alice\n");
        else if (dp[0][slen - 1] == -1) printf("Bob\n");
        else printf("Draw\n");
    }
    return 0;
}