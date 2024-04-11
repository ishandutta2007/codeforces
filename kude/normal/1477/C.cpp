#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<ll,ll>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<P> xy(n);
    for(auto& [x, y]: xy) cin >> x >> y;
    VI p(n);
    iota(all(p), 0);
    auto check = [&](int i, int j, int k) {
        int a = p[i], b = p[j], c = p[k];
        ll dx1 = xy[a].first - xy[b].first;
        ll dy1 = xy[a].second - xy[b].second;
        ll dx2 = xy[c].first - xy[b].first;
        ll dy2 = xy[c].second - xy[b].second;
        return dx1 * dx2 + dy1 * dy2 > 0;
    };
    for(int i = 0; i + 2 <= n - 1; ++i) {
        if (!check(i, i + 1, i + 2)) {
            swap(p[i+1], p[i+2]);
            for(int j = i - 1; j >= 0; --j) {
                if (!check(j, j + 1, j + 2)) {
                    swap(p[j+1], p[j+2]);
                } else break;
            }
        }
    }
    rep(i, n) cout << p[i] + 1 << " \n"[i + 1 == n];
}