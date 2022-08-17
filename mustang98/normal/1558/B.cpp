#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 4000111, inf = 1000111222;
int mod;
ll dp[max_n];
ll prs[max_n];
ll n;
ll get_sum(int from, int to) {
    return (prs[from] - prs[to + 1] + mod) % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> mod;
    dp[n] = 1;
    prs[n] = 1;
    for (int i = n - 1; i >= 1; --i) {
        dp[i] = get_sum(i + 1, n);
        for (int k = 2;;++k) {
            ll from = 1LL * i * k;
            if (from > n) break;
            ll to = min(n, 1LL*i * k + k - 1);
            dp[i] += get_sum(from, to);
            if (dp[i] >= mod) {
                dp[i] -= mod;
            }
        }
        prs[i] = prs[i + 1] + dp[i];
        if (prs[i] >= mod) {
            prs[i] -= mod;
        }
    }
    cout << dp[1] << endl;
    return 0;
}