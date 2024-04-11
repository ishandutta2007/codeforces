#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
        int ans = 0;
        rep(i, n) {
            if (s[i] == '_') continue;
            if (i + 1 < n && s[i+1] != '_' && s[i] == s[i+1]) {
                ans++;
                s[i+1] = '_';
            }
            if (i + 2 < n && s[i] == s[i+2]) {
                ans++;
                s[i+2] = '_';
            }
        }
        cout << ans << '\n';
    }
}