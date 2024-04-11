#include <bits/stdc++.h>
using namespace std;

const int Maxn = 50;

string dp[Maxn];

int main()
{
    for (int i = 0; i < 1 << 9; i++) {
        int sum = 0;
        string str;
        for (int j = 0; j < 9; j++) if (i & 1 << j) {
            sum += j + 1;
            str += string(1, j + 1 + '0');
        }
        if (dp[sum].size() == 0 || str.length() < dp[sum].length() || str.length() == dp[sum].length() && str < dp[sum])
            dp[sum] = str;
    }
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        printf("%s\n", dp[n].c_str());
    }
    return 0;
}