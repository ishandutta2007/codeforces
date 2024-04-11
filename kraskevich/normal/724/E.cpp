#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll) 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> s(n);
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    vector<ll> n_dp(n + 1);
    for (int i = 0; i < n; i++) {
        fill(n_dp.begin(), n_dp.end(), INF);
        for (int sc = 0; sc < n; sc++) {
            n_dp[sc + 1] = min(n_dp[sc + 1], dp[sc] + p[i] + (i - sc) * c);
            n_dp[sc] = min(n_dp[sc], dp[sc] + s[i]);
        }
        dp = n_dp;
    }
    cout << *min_element(dp.begin(), dp.end()) << endl;
    return 0;
}