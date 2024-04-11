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
        rep(i, n) if ((i & 1) && s[i] != '?') {
            s[i] ^= '0' ^ '1';
        }
        // cout << s << endl;
        ll ans = ll(n + 1) * n / 2;
        int r = 0;
        int cnt0 = 0, cnt1 = 0;
        rep(i, n) {
            while(r < n && (cnt0 == 0 || cnt1 == 0)) {
                if (s[r] == '0') cnt0++;
                else if (s[r] == '1') cnt1++;
                r++;
            }
            // cout << i << ' ' << cnt0 << ' ' << cnt1 << endl;
            if (cnt0 == 0 || cnt1 == 0) break;
            ans -= n - r + 1;
            if (s[i] == '0') cnt0--;
            else if (s[i] == '1') cnt1--;
        }
        cout << ans << '\n';
    }
}