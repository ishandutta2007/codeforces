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
        int n, u, v;
        cin >> n >> u >> v;
        VI a(n);
        rep(i, n) cin >> a[i];
        int d = 0;
        rep(i, n - 1) chmax(d, abs(a[i] - a[i+1]));
        int ans = 0;
        if (d == 0) ans = v + min(u, v);
        else if (d == 1) ans = min(u, v);
        else ans = 0;
        cout << ans << '\n';
    }
}