#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int dp[max_n];
int pr[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> pr[i];
        --pr[i];
    }

    for (int i = 0; i < n; ++i) {
        dp[i] = min(n - 1, i + k) - max(0, i - k) + 1;
        if (pr[i] != -1) {
            dp[i] += dp[pr[i]];
            int inters = min(n - 1, pr[i] + k) - max(0, i - k) + 1;
            if (inters > 0) {
                dp[i] -= inters;
            }
        }
        cout << dp[i] << ' ';
    }

    return 0;
}