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

int x[110], y[110], xpy[110], xmy[110];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        rep(i, n) {
            cin >> x[i] >> y[i];
            xpy[i] = x[i] + y[i];
            xmy[i] = x[i] - y[i];
        }
        bool ok[n];
        rep(i, n) ok[i] = true;
        {
            int mx, mn;
            mx = mn = xpy[0];
            rep(i, n) {
                chmin(mn, xpy[i]);
                chmax(mx, xpy[i]);
            }
            rep(i, n) if (!(xpy[i] - mn <= k && mx - xpy[i] <= k)) ok[i] = false;
        }
        {
            int mx, mn;
            mx = mn = xmy[0];
            rep(i, n) {
                chmin(mn, xmy[i]);
                chmax(mx, xmy[i]);
            }
            rep(i, n) if (!(xmy[i] - mn <= k && mx - xmy[i] <= k)) ok[i] = false;
        }
        int ans = -1;
        rep(i, n) if (ok[i]) ans = 1;
        cout << ans << '\n';
    }
}