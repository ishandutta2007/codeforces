#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int dp[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int n =  s.size();
    int sum = 0;
    int z[3];
    z[0] = z[1] = z[2] = -1;
    dp[0] = 0;
    if ((s[0] - 48) % 3 == 0) {
        dp[0] = 1;
    }
    z[(s[0] - 48) % 3] = 0;
    sum = (s[0] - 48) % 3;
    for (int i = 1; i < n; ++i) {
        int c = (s[i] - '0') % 3;
        dp[i] = dp[i - 1];
        sum += c;
        sum %= 3;
        if (z[sum] != -1) {
            dp[i] = max(dp[i], 1 + dp[z[sum]]);
        }
        if (sum % 3 == 0) {
            dp[i] = max(1, dp[i]);
        }
        z[sum] = i;
    }
    cout << dp[n - 1];
    return 0;
}