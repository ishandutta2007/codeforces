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

struct S {
    int a, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<S> d(n);
    rep(i, n) cin >> d[i].a >> d[i].c;
    sort(all(d), [](S x, S y) {return x.a < y.a;});
    ll ans = 0;
    rep(i, n) ans += d[i].c;
    int i_free = 0;
    int mx = -1;
    rep(i, n) {
        int a = d[i].a, c = d[i].c;
        if (i == 0) {
            mx = a + c;
        }
        if (mx < a) {
            ans += a - mx;
        }
        int h = a + c;
        chmax(mx, h);
    }
    cout << ans << '\n';
}