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
    cout << fixed << setprecision(16);
    while(tt--) {
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i];
        sort(all(a));
        ll s1 = 0, s2 = 0;
        rep(i, n) s2 += a[i];
        double ans = -1e18;
        rep(i, n - 1) {
            s1 += a[i], s2 -= a[i];
            int c1 = i + 1, c2 = n - c1;
            chmax(ans, double(s1) / c1 + double(s2) / c2);
        }
        cout << ans << '\n';
    }
}