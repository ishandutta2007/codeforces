
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

const int N = 1e5 + 5;
int t, n;
ll s[N];
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        fill(dp + 1, dp + n + 1, 0);
        rep(i, 1, n + 1) {
            cin >> s[i];
        }
        rep(i, 1, n + 1) {
            dp[i]++;
            for(int j = 2 * i; j <= n; j += i) {
                if(s[i] < s[j]) {
                    dp[j] = max(dp[j], dp[i]);
                }
            }
        }
        cout << *max_element(dp + 1, dp + n + 1) << '\n';
    }
}