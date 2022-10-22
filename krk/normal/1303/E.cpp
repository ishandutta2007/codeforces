#include <bits/stdc++.h>
using namespace std;

const int Maxn = 405;
const int Inf = 1000000000;

int T;
string s, t;
int dp[Maxn];

bool Solve(int x)
{
    fill(dp, dp + Maxn, -Inf);
    dp[x] = 0;
    for (int i = 0; i < s.length(); i++)
        for (int j = int(t.length()); j >= x; j--) if (dp[j] >= 0) {
            if (j + 1 <= t.length() && t[j] == s[i]) dp[j + 1] = max(dp[j + 1], dp[j]);
            if (dp[j] < x && s[i] == t[dp[j]]) dp[j]++;
        }
    return dp[t.length()] >= x;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        cin >> s;
        cin >> t;
        bool ok = false;
        for (int i = 0; i < t.length() && !ok; i++)
            ok = Solve(i);
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}