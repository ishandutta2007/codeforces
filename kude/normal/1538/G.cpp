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
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if (a > b) swap(a, b);
        ll d = b - a;
        ll l = 0, r = 1001001001;
        while(r - l > 1) {
            ll c = (r + l) >> 1;
            ll nx = x - c * a, ny = y - c * a;
            bool ok = nx >= 0 && ny >= 0 && (d == 0 || nx / d + ny / d >= c);
            if (ok) l = c;
            else r = c;
        }
        cout << l << '\n';
    }
}