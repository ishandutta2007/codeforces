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
        VI h(n), w(n);
        vector<tuple<int, int, int>> s;
        rep(i, n) {
            cin >> h[i] >> w[i];
            rep(_, 2) {
                s.emplace_back(h[i], w[i], i);
                swap(h[i], w[i]);
            }
        }
        sort(all(s));
        vector<tuple<int, int, int>> s2;
        for(auto [hi, wi, i]: s) {
            if (!s2.empty() && wi >= get<1>(s2.back())) continue;
            s2.emplace_back(hi, wi, i);
        }
        //for(auto [x, y, z] : s2) {
        //    cerr << "tt" << x << ' ' << y << ' ' << z << endl;
        //}
        rep(i, n) {
            auto it = lower_bound(all(s2), tuple<int, int, int>(h[i], -1, -1));
            int ans;
            if (it == s2.begin()) ans = -1;
            else {
                it--;
                if (get<1>(*it) < w[i]) {
                    ans = get<2>(*it) + 1;
                } else {
                    ans = -1;
                }
            }
            cout << ans << " \n"[i + 1 == n];
        }
    }
}