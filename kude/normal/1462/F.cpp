#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
        int n;
        cin >> n;
        vector<int> ls(n), rs(n);
        vector<P> s(n);
        rep(i, n) {
            int l, r;
            cin >> l >> r;
            ls[i] = l;
            rs[i] = r;
            s[i] = {l, r};
        }
        sort(all(ls));
        sort(all(rs));
        int ans = n;
        for(auto [l, r]: s) {
            int ri = lower_bound(all(rs), l) - rs.begin();
            int li = upper_bound(all(ls), r) - ls.begin();
            chmin(ans, ri + n - li);
        }
        cout << ans << '\n';
    }
}