
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

const int N = 3e5 + 5;
int n;
ll a[N], b[N], dp[N][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n;
        rep(i, 1, n + 1) {
            cin >> a[i] >> b[i];
        }
        rep(i, 1, n + 1) {
            rep(d, 0, 4) {
                dp[i][d] = LLONG_MAX;
                rep(d2, 0, 4) {
                    if(i == 1 || a[i - 1] + d2 != a[i] + d) {
                        dp[i][d] = min(dp[i][d], b[i] * d + dp[i - 1][d2]);
                    }
                }
            }
        }
        cout << *min_element(dp[n], dp[n] + 4) << '\n';
    }
}