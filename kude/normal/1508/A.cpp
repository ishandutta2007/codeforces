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
        int n;
        cin >> n;
        VVI s(3, VI(2 * n));
        rep(i, 3) rep(j, 2 * n) {
            char c;
            cin >> c;
            int x = c - '0';
            s[i][j] = x;
        }
        int cnt[3] = {};
        rep(i, 3) rep(j, 2 * n) cnt[i] += s[i][j] == 1;
        int t = 0;
        rep(i, 3) t += cnt[i] >= n;
        bool flip = false;
        if (t < 2) {
            flip = true;
            rep(i, 3) rep(j, 2 * n) s[i][j] ^= 1;
            rep(i, 3) cnt[i] = 2 * n - cnt[i];
        }
        if (cnt[0] < n) swap(s[0], s[2]), swap(cnt[0], cnt[2]);
        else if (cnt[1] < n) swap(s[1], s[2]), swap(cnt[1], cnt[2]);
        int mx = max(cnt[0], cnt[1]);
        VI ans;
        int i0 = 0, i1 = 0;
        rep(i, mx) {
            int c0 = 0, c1 = 0;
            while(i0 < 2 * n && s[0][i0] == 0) c0++, i0++;
            while(i1 < 2 * n && s[1][i1] == 0) c1++, i1++;
            int c = max(c0, c1);
            rep(_, c) ans.push_back(0);
            ans.push_back(1);
            i0++, i1++;
        }
        ans.resize(3 * n, 0);
        if (flip) {
            rep(i, 3 * n) ans[i] ^= 1;
        }
        rep(i, 3 * n) cout << ans[i];
        cout << '\n';
    }
}