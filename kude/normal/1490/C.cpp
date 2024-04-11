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

bool solve(ll x) {
    for(ll a = 1; a * a * a < x; ++a) {
        ll rest = x - a * a * a;
        ll l = 1, r = 10001;
        while(r - l > 1) {
            ll c = l + r >> 1;
            if (c * c * c <= rest) l = c;
            else r = c;
        }
        if (l * l * l == rest) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        ll x;
        cin >> x;
        cout << (solve(x) ? "YES\n" : "NO\n");
    }
}