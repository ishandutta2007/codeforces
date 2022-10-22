#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> dp(2, 2), ndp(2);
        dp[0] = 0;
        rep(i, n) {
            int x = s[i] - '0';
            ndp.assign(2, 2);
            if (dp[0] != 2) {
                if (dp[0] <= x) chmin(ndp[0], x);
                chmin(ndp[1], dp[0]);
            }
            if (dp[1] != 2) {
                if (dp[1] <= x) chmin(ndp[0], x);
            }
            swap(dp, ndp);
        }
        bool ok = min(dp[0], dp[1]) < 2;
        cout << (ok ? "YES\n" : "NO\n");
    }
}