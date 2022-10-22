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
        string s;
        cin >> s;
        stringstream ss(s);
        int s_int;
        ss >> s_int;
        int k;
        cin >> k;
        VI ds;
        ll ans = 1111111111;
        if (k >= 2) {
            ll x = 1;
            while(x < s_int) x *= 10;
            chmin(ans, x);
        } else {
            ll x = 1;
            while(x < s_int) x = 10 * x + 1;
            chmin(ans, x);
        }

        ll p10[19];
        p10[0] = 1;
        rep(i, 18) p10[i + 1] = p10[i] * 10;

        auto check = [&] {
            if (ds.size() == 1 && ds[0] == 0) return;
            int n = s.size();
            ll now = 0;
            rep(i, n) {
                int d = s[i] - '0';
                auto it1 = lower_bound(all(ds), d);
                if (it1 == ds.end()) return;
                auto it2 = next(it1);
                if (*it1 > d || it2 != ds.end()) {
                    ll x = now * 10 + (*it1 > d ? *it1 : *it2);
                    int r = n - (i + 1);
                    x = p10[r] * x + (p10[r] - 1) / 9 * ds[0];
                    chmin(ans, x);
                }
                if (*it1 > d) return;
                now = now * 10 + d;
            }
            chmin(ans, now);
        };

        auto dfs = [&](auto&& self, int i) -> void {
            if (ds.size() == k || i == 10) {
                assert(ds.size() == k);
                check();
                return;
            }
            int rest = 10 - i;
            if (ds.size() + rest > k) {
                self(self, i + 1);
            }
            ds.push_back(i);
            self(self, i + 1);
            ds.pop_back();
        };
        dfs(dfs, 0);
        cout << ans << '\n';
    }
}