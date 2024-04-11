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
        ll W;
        cin >> n >> W;
        vector<pair<ll,int>> w(n);
        rep(i, n) {
            cin >> w[i].first;
            w[i].second = i;
        }
        sort(rall(w));
        bool ok = false;
        ll now = 0;
        VL items;
        rep(i, n) {
            ll wi = w[i].first;
            while(wi + now > W && !items.empty()) {
                now -= w[items.back()].first; items.pop_back();
            }
            if (wi + now > W) continue;
            now += wi; items.push_back(i);
            if (W <= now * 2 && now <= W) {
                ok = true;
                int sz = items.size();
                cout << sz << '\n';
                rep(i, sz) cout << w[items[i]].second + 1 << " \n"[i+1 == sz];
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
        }
    }
}