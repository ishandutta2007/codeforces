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

int a[500], b[500], ans[500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int k, n, m;
        cin >> k >> n >> m;
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> b[i];
        int pb = 0;
        int idx_ans = 0;
        rep(i, n + 1) {
            while(pb < m && b[pb] <= k) {
                ans[idx_ans++] = b[pb];
                if (b[pb++] == 0) k++;
            }
            if (i == n) break;
            if (a[i] <= k) {
                ans[idx_ans++] = a[i];
                if (a[i] == 0) k++;
            } else break;
        }
        if (idx_ans != n + m) {
            cout << -1 << '\n';
        } else {
            rep(i, idx_ans) cout << ans[i] << " \n"[i + 1 == idx_ans];
        }
    }
}