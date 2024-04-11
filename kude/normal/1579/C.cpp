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
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> s(n);
        rep(i, n) cin >> s[i];
        VVI d(n, VI(m));
        rep(i, n) rep(j, m) if (s[i][j] == '*') {
            int cnt0 = 0;
            int x = i - 1, y = j - 1;
            while(0 <= x && 0 <= y && s[x][y] == '*') {
                cnt0++;
                x--, y--;
            }
            int cnt1 = 0;
            x = i - 1, y = j + 1;
            while(0 <= x && y < m && s[x][y] == '*') {
                cnt1++;
                x--, y++;
            }
            d[i][j] = min(cnt0, cnt1);
        }
        rep(i, n) rep(j, m) if (d[i][j] >= k) {
            for(int h = 0; h <= d[i][j]; h++) {
                s[i - h][j + h] = s[i - h][j - h] = '.';
            }
        }
        bool ok = true;
        rep(i, n) rep(j, m) if (s[i][j] == '*') ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }
}