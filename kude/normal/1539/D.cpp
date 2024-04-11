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
    cin >> n;
    vector<pair<ll, ll>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    sort(all(ab), [](auto x, auto y) {return x.second < y.second;});
    ll tot = 0;
    rep(i, n) tot += ab[i].first;
    ll nxt = 0;
    ll gain = 0;
    for(auto [a, b]: ab) {
        chmax(nxt, b);
        if (nxt >= tot) break;
        ll new_nxt = min(nxt + a, tot);
        gain += new_nxt - nxt;
        nxt = new_nxt;
    }
    ll ans = 2 * tot - gain;
    cout << ans << '\n';
}