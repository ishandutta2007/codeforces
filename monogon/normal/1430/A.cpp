
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

const int N = 1005;
int dp[N];
int a[3] = {3, 5, 7};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[0] = 0;
    rep(i, 1, N) {
        dp[i] = -1;
        rep(j, 0, 3) {
            for(int x = i - a[j]; x >= 0; x -= a[j]) {
                if(dp[x] != -1) dp[i] = j;
            }
        }
    }
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        int ans[3] = {0, 0, 0};
        if(dp[n] == -1) {
            cout << -1 << '\n';
        }else {
            while(n > 0) {
                ans[dp[n]]++;
                n -= a[dp[n]];
            }
            cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
        }
    }
}