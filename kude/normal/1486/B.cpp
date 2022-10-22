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
        VI x(n), y(n);
        rep(i, n) cin >> x[i] >> y[i];
        sort(all(x));
        sort(all(y));
        ll sx = x[(n - 1) / 2], tx = x[n / 2], sy = y[(n - 1) / 2], ty = y[n / 2];
        ll ans = (tx - sx + 1) * (ty - sy + 1);
        cout << ans << '\n';
    }
}