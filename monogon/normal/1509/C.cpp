#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2005;
int n;
ll a[N], dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    rep(len, 1, n + 1) {
        rep(i, 0, n - len + 1) {
            dp[len][i] = a[i + len - 1] - a[i] + min(dp[len - 1][i], dp[len - 1][i + 1]);
        }
    }
    cout << dp[n][0] << '\n';
}