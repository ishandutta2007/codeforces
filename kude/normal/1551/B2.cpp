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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> hist(n + 1);
        rep(i, n) {
            int a;
            cin >> a;
            hist[a].push_back(i);
        }
        int c1 = 0, c2 = 0;
        for(auto &h: hist) {
            int x = h.size();
            if (x >= k) c2++;
            else c1 += x;
        }
        c1 = c1 / k * k;
        VI ans(n, -1);
        int nxt = 0;
        for(auto &h: hist) {
            if (h.size() >= k) {
                rep(i, k) {
                    int idx = h[i];
                    ans[idx] = i;
                }
            } else {
                int sz = min<int>(h.size(), c1);
                rep(i, sz) {
                    int idx = h[i];
                    ans[idx] = nxt++;
                    if (nxt >= k) nxt -= k;
                }
                c1 -= sz;
            }
        }
        rep(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
    }
}