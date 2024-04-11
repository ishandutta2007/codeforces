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
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        int ans = n + m;
        rep(ra, n + 1) rep(la, ra + 1) rep(rb, m + 1) rep(lb, rb + 1) {
            int alen = ra - la, blen = rb - lb;
            if (alen != blen) continue;
            if (a.substr(la, alen) == b.substr(lb, blen)) {
                chmin(ans, n - alen + m - blen);
            }
        }
        cout << ans << '\n';
    }
}