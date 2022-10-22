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
    int n;
    VL c(4);
    cin >> n;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        x /= 2, y /= 2;
        if (x % 2 == 0) {
            if (y % 2 == 0) c[0]++;
            else c[1]++;
        } else {
            if (y % 2 == 0) c[2]++;
            else c[3]++;
        }
    }
    auto comb3 = [](ll x) {
        return x * (x - 1) * (x - 2) / 6;
    };
    auto comb2 = [](ll x) {
        return x * (x - 1) / 2;
    };
    ll ans = 0;
    rep(i, 4) ans += comb3(c[i]);
    rep(i, 4) ans += comb2(c[i]) * (n - c[i]);
    cout << ans << endl;
}