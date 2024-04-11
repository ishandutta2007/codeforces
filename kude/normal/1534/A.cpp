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
        int n, m;
        cin >> n >> m;
        vector<string> g(n);
        rep(i, n) cin >> g[i];
        int t = 0;
        rep(i, n) rep(j, m) {
            if (g[i][j] == 'R') {
                t = (i ^ j ^ 0) & 1;
            } else if (g[i][j] == 'W') {
                t = (i ^ j ^ 1) & 1;
            }
        }
        bool ok = true;
        rep(i, n) rep(j, m) {
            if (g[i][j] == '.') {
                g[i][j] = ((i ^ j ^ t) & 1) == 0 ? 'R' : 'W';
            } else if (g[i][j] == 'R') {
                ok &= ((i ^ j ^ 0) & 1) == t;
            } else {
                ok &= ((i ^ j ^ 1) & 1) == t;
            }
        }
        if (ok) {
            cout << "YES\n";
            rep(i, n) cout << g[i] << '\n';
        } else {
            cout << "NO\n";
        }
    }
}