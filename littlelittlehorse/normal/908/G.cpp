#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N(707);
int dp[N][2], dp1[N][2];
typedef long long LL;
int a[N], pw[N];
int mod(1e9 + 7);

void add(int & x, int y) {
    if((x += y) >= mod) x -= mod;
}
int main() {
    string st;
    cin >> st;
    int n = st.size();
    for(int i(0); i < n; i++)
        a[i + 1] = st[i] - '0';
    pw[0] = 1;
    for(int i(1); i <= n; i++)
        pw[i] = 10ll * pw[i - 1] % mod;
    int ans = 0;
    for(int u(0); u <= 8; u++) {
        memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
        for(int i(1); i <= n; i++) {
            memset(dp1, 0, sizeof(dp1));
            for(int j(0); j < i; j++) {
                for(int k(0); k <= 9; k++) {
                    add(dp1[j + (k <= u)][0], dp[j][0]);
                    if(k == a[i]) {
                        add(dp1[j + (k <= u)][1], dp[j][1]);
                    }else if(k < a[i]) {
                        add(dp1[j + (k <= u)][0], dp[j][1]);    
                    }
                }
            }
            memcpy(dp, dp1, sizeof(dp));
        }
        int sum((dp[0][0] + dp[0][1]) % mod);
        for(int i(1); i <= n; i++) {
            ans = (ans + (LL)sum * pw[n - i]) % mod;
            sum = (sum + (LL)dp[i][0] + dp[i][1]) % mod;
        }
    }
    cout << ans << endl;
}