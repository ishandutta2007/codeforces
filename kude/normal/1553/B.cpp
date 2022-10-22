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
        string s, t;
        cin >> s >> t;
        const int n = s.size(), m = t.size();
        bool found = false;
        rep(i2, n) rep(i1, i2 + 1) {
            int mxl = i2 - i1 + i2 + 1;
            if (m > mxl) continue;
            int idx = 0;
            bool ok = true;
            for(int i = i1; i < i2; i++) if (s[i] != t[idx++]) {
                ok = false;
                break;
            }
            if (ok) for(int i = i2; idx < m; i--) if (s[i] != t[idx++]) {
                ok = false;
                break;
            }
            if (ok) {
                found = true;
                break;
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }
}