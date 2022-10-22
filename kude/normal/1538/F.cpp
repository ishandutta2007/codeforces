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
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        while(l || r) {
            int nl = l / 10, dl = l % 10, nr = r / 10, dr = r % 10;
            l = nl, r = nr;
            if (nl == nr) ans += dr - dl;
            else {
                ans += 10 - dl;
                nl++;
                ans += dr;
                ans += 10 * (nr - nl);
            }
        }
        cout << ans << '\n';
    }
}