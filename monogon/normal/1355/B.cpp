
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

const int N = 2e5 + 5;
int t, n, e[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 1, n + 1) cin >> e[i];
        sort(e + 1, e + n + 1);
        rep(i, 1, n + 1) {
            dp[i] = e[i] <= i ? max(dp[i - 1], 1 + dp[i - e[i]]) : dp[i - 1];
        }
        cout << dp[n] << '\n';
    }
}