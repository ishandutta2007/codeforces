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

int cnt[20000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI s(n);
        rep(i, n) {
            char c;
            cin >> c;
            s[i] = c - 'a';
        }
        int b = 0;
        for(int k = 0; k <= 3; k++) {
            for(int i = 0; i + k <= n; i++) {
                int t = 0;
                rep(j, k) t = t * 26 + s[i + j];
                cnt[b + t]++;
            }
            b = b * 26 + 1;
        }
        b = 0;
        bool found = false;
        for(int k = 0; k <= 3; k++) {
            int sz = b * 26 + 1 - b;
            for(int i = 0; i < sz; i++) if (cnt[b + i] == 0) {
                found = true;
                string ans;
                rrep(_, k) ans += 'a' + i % 26, i /= 26;
                reverse(all(ans));
                cout << ans << '\n';
                break;
            }
            if (found) break;
            b = b * 26 + 1;
        }
        b = 0;
        for(int k = 0; k <= 3; k++) {
            for(int i = 0; i + k <= n; i++) {
                int t = 0;
                rep(j, k) t = t * 26 + s[i + j];
                cnt[b + t] = 0;
            }
            b = b * 26 + 1;
        }
    }
}