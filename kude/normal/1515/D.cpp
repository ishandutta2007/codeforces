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
        VI hist(n);
        rep(_, l) {
            int c;
            cin >> c, c--;
            hist[c] += 1;
        }
        rep(_, r) {
            int c;
            cin >> c, c--;
            hist[c] -= 1;
        }
        if (l < r) {
            swap(l, r);
            rep(i, n) hist[i] = -hist[i];
        }
        int ans = 0;
        int rest = l - r;
        rep(i, n) if (hist[i] > 0) {
            int cnt = min(rest, hist[i] / 2 * 2);
            hist[i] -= cnt;
            rest -= cnt;
            ans += cnt / 2;
        }
        ans += rest;
        rep(i, n) if (hist[i] < 0) {
            ans += -hist[i];
        }
        cout << ans << '\n';
    }
}