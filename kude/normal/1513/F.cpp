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
    VI a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, n) ans += abs(a[i] - b[i]);
    int A = 0;
    rep(_, 2) {
        VI vl, vr;
        rep(i, n) {
            if (a[i] < b[i]) vr.push_back(i);
            else vl.push_back(i);
        }
        {
            vector<tuple<int, int, int>> events;
            for(int i: vr) {
                events.emplace_back(a[i], 0, i);
            }
            for(int i: vl) {
                events.emplace_back(b[i], 1, i);
            }
            sort(all(events));
            set<int> s;
            for(auto [_, type, i]: events) {
                if (type == 0) {
                    s.insert(b[i]);
                } else {
                    if (!s.empty()) {
                        chmax(A, min(a[i], *s.rbegin()) - b[i]);
                    }
                }
            }
        }
        swap(a, b);
    }
    cout << ans - 2 * A << '\n';
}