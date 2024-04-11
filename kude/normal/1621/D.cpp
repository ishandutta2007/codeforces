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

int c[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        rep(i, 2 * n) rep(j, 2 * n) cin >> c[i][j];
        int mn = 1001001001;
        for(int i : {0, n - 1}) {
            for(int j : {2 * n - 1, n}) {
                chmin(mn, c[i][j]);
            }
        }
        for(int j : {0, n - 1}) {
            for(int i : {2 * n - 1, n}) {
                chmin(mn, c[i][j]);
            }
        }
        ll ans = mn;
        for(int i = n; i < 2 * n; i++) {
            for(int j = n; j < 2 * n; j++) {
                ans += c[i][j];
            }
        }
        cout << ans << '\n';
    }
}