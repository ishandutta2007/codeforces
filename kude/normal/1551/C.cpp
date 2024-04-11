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
        int n;
        cin >> n;
        vector<string> s(n);
        rep(i, n) cin >> s[i];
        int ans = 0;
        for(char p = 'a'; p <= 'z'; p++) {
            VI d(n);
            rep(i, n) {
                int score = 0;
                for(auto c: s[i]) {
                    if (c == p) score++;
                    else score--;
                }
                d[i] = score;
            }
            sort(rall(d));
            if (d[0] <= 0) continue;
            int now = d[0];
            ll s = 0;
            for(int i = 1; i < n; i++) {
                if (now > 0) chmax(ans, i);
                now += d[i];
            }
            if (now > 0) chmax(ans, n);
        }
        cout << ans << '\n';
    }
}