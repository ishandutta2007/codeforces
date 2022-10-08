
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

const int N = 5005;
int n;
ll a[N];
ll dp1[N][N / 2], dp2[N][N / 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    a[0] = 1e5 + 5;
    rep(k, 1, (n + 1) / 2 + 1) {
        dp1[0][k] = dp2[0][k] = 1e18;
    }
    rep(i, 1, n + 1) {
        rep(k, 1, (i + 1) / 2 + 1) {
            if(i == 1) {
                dp1[i][k] = 0;
                dp2[i][k] = 1e18;
            }else {
                dp1[i][k] = min(max(0LL, a[i - 1] - a[i] + 1) + dp2[i - 2][k - 1],
                            max(0LL, a[i - 1] - min(a[i], a[i - 2]) + 1) + dp1[i - 2][k - 1]);
                dp2[i][k] = min(dp2[i - 1][k], max(0LL, a[i] - a[i - 1] + 1) + dp1[i - 1][k]);
            }
            // cout << dp1[i][k] << ' ';
        }
        rep(k, (i + 1) / 2 + 1, (n + 1) / 2 + 1) {
            dp1[i][k] = 1e18;
            dp2[i][k] = 1e18;
        }
        // cout << endl;
    }
    rep(k, 1, (n + 1) / 2 + 1) {
        cout << min(dp1[n][k], dp2[n][k]) << ' ';
    }
    cout << '\n';
}