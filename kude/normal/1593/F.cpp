#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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

bool dp[2][2][40][40][81];
bool ndp[2][2][40][40][81];

struct S {
    unsigned char ba, bb, ra, rb, d;
    bool choice;
};
S pre[41][2][2][40][40][81];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, a, b;
        cin >> n >> a >> b;
        rep(ba, 2) rep(bb, 2) rep(ra, a) rep(rb, b) rep(d, 81) dp[ba][bb][ra][rb][d] = false;
        dp[0][0][0][0][40] = true;
        string X;
        cin >> X;
        rep(i, n) {
            int x = X[i] - '0';
            rep(ba, 2) rep(bb, 2) rep(ra, a) rep(rb, b) rep(d, 81) ndp[ba][bb][ra][rb][d] = false;
            rep(ba, 2) rep(bb, 2) rep(ra, a) rep(rb, b) rep(d, 81) if (dp[ba][bb][ra][rb][d]) {
                int nra = (10 * ra + x) % a, nrb = (10 * rb + x) % b;
                ndp[1][bb][nra][rb][d + 1] = true;
                pre[i + 1][1][bb][nra][rb][d + 1] = {ba, bb, ra, rb, d, 0};
                ndp[ba][1][ra][nrb][d - 1] = true;
                pre[i + 1][ba][1][ra][nrb][d - 1] = {ba, bb, ra, rb, d, 1};
            }
            rep(ba, 2) rep(bb, 2) rep(ra, a) rep(rb, b) rep(d, 81) dp[ba][bb][ra][rb][d] = ndp[ba][bb][ra][rb][d];
        }
        int min_diff = 100;
        int d = -1;
        rep(x, 81) if (dp[1][1][0][0][x]) {
            int diff = abs(40 - x);
            if (diff < min_diff) {
                min_diff = diff;
                d = x;
            }
        }
        if (min_diff == 100) {
            cout << -1 << '\n';
            continue;
        }
        int ba = 1, bb = 1, ra = 0, rb = 0;
        string ans;
        for(int i = n; i; i--) {
            const S& p = pre[i][ba][bb][ra][rb][d];
            ans += "RB"[p.choice];
            ba = p.ba; bb = p.bb; ra = p.ra; rb = p.rb; d = p.d;
        }
        reverse(all(ans));
        cout << ans << '\n';
    }
}