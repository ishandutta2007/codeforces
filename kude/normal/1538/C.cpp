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
        int n, l, r;
        cin >> n >> l >> r;
        r++;
        VI a(n);
        rep(i, n) cin >> a[i];
        sort(all(a));
        int pl = n, pr = n;
        ll ans = 0;
        for(int x: a) {
            while(pl && a[pl - 1] + x >= l) pl--;
            while(pr && a[pr - 1] + x >= r) pr--;
            ans += pr - pl;
        }
        for(int x: a) ans -= l <= 2 * x && 2 * x < r;
        cout << ans / 2 << '\n';
    }
}