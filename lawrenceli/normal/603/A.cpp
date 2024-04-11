#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100100;

int n;
char s[maxn];
bool a[maxn];
int dp[maxn][2][3];

void setmax(int& a, int b) { if (a < b) a = b; }

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';
    
    dp[0][a[0]][0] = 1;
    dp[0][!a[0]][0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++)
                dp[i+1][j][k] = dp[i][j][k];

        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++) {
                int k2 = k + (a[i + 1] == j);
                if (k2 < 3)
                    setmax(dp[i+1][a[i+1]][k2], dp[i][j][k] + 1);
            }
    }
     
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++)
                ans = max(ans, dp[i][j][k]);
    cout << ans << '\n';
}