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
    int n, m;
    cin >> n >> m;
    n--;
    VI a(m);
    rep(i, m) cin >> a[i];
    VVI s(n, VI(m));
    rep(i, n) rep(j, m) cin >> s[i][j];
    auto check = [&](auto&& self, int rest=2) {
        VI d;
        rep(i, n) {
            d.clear();
            rep(j, m) if (s[i][j] != a[j]) d.push_back(j);
            int sz = d.size();
            if (sz <= 2) continue;
            if (sz > 2 + rest) return false;
            for(auto j: d) {
                int aj_orig = a[j];
                a[j] = s[i][j];
                if (self(self, rest - 1)) return true;
                a[j] = aj_orig;
            }
            return false;
        }
        return true;
    };
    if (check(check)) {
        cout << "Yes\n";
        rep(j, m) cout << a[j] << " \n"[j + 1 == m];
    } else {
        cout << "No\n";
    }
}