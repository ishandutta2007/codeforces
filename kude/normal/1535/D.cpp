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
    int k;
    cin >> k;
    string s;
    cin >> s;
    VI idx(1 << k), idx_inv(1 << k);
    {
        int p = 0;
        for(int b = 1 << (k - 1); b; b >>= 1) {
            for(int i = b; i < 2 * b; i++) idx[i] = p++;
        }
        for(int i = 1; i < (1 << k); i++) {
            idx_inv[idx[i]] = i;
        }
    }
    VI dp(1 << (k + 1), 1);
    rep(i, (1 << k) - 1) {
        int p = idx_inv[i];
        if (s[i] == '0') dp[p] = dp[2 * p];
        else if (s[i] == '1') dp[p] = dp[2 * p + 1];
        else dp[p] = dp[2 * p] + dp[2 * p + 1];
    }
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        t--;
        char c;
        cin >> c;
        s[t] = c;
        for(int p = idx_inv[t]; p; p >>= 1) {
            int i = idx[p];
            if (s[i] == '0') dp[p] = dp[2 * p];
            else if (s[i] == '1') dp[p] = dp[2 * p + 1];
            else dp[p] = dp[2 * p] + dp[2 * p + 1];
        }
        cout << dp[1] << '\n';
    }
    return 0;
}