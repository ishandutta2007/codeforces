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
        int n, m;
        cin >> n >> m;
        map<int, int> bs;
        bs[n + 1] = 3;
        rep(_, m) {
            int r, c;
            cin >> r >> c;
            --r;
            bs[c] |= 1 << r;
        }
        int pre = -1, state = 0;
        bool ok = true;
        for(auto [c, b]: bs) {
            if (state) {
                if ((c - 1 - pre) % 2) {
                    state ^= 3;
                }
            }
            if (b == 3) {
                if (state != 0) {
                    ok = false;
                }
            } else if (b == 1) {
                if (state == 1) {
                    ok = false;
                } else {
                    if (state) state = 0;
                    else state = 2;
                }
            } else {
                if (state == 2) {
                    ok = false;
                } else {
                    if (state) state = 0;
                    else state = 1;
                }
            }
            if (!ok) break;
            pre = c;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}