
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
int n, m;
string s, p;
int ans[N];
int b[N], dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> p;
    n = s.length();
    m = p.length();
    rep(i, 0, n) {
        int k = 0, j = i;
        while(j < n && k < m) {
            if(s[j] == p[k]) k++;
            j++;
        }
        if(k == m) {
            b[i] = j;
        }else {
            b[i] = INT_MAX;
        }
    }
    // rep(i, 0, n) {
    //     cout << b[i] << ' ';
    // }
    // cout << endl;
    for(int i = n; i >= 0; i--) {
        rep(k, 0, n + 1) {
            if(i == n) {
                if(k == 0) dp[i][k] = 0;
                else dp[i][k] = INT_MAX;
            }else {
                dp[i][k] = dp[i + 1][k];
                if(b[i] != INT_MAX && dp[b[i]][k - 1] != INT_MAX) {
                    dp[i][k] = min(dp[i][k], b[i] - i + dp[b[i]][k - 1]);
                }
            }
        }
    }
    rep(k, 0, n + 1) {
        if(dp[0][k] != INT_MAX) {
            int l = dp[0][k] - k * m;
            int r = n - k * m;
            rep(i, l, r + 1) {
                ans[i] = k;
            }
        }
    }
    rep(i, 0, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}