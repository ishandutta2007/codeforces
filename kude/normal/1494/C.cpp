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
        int n, m;
        cin >> n >> m;
        VI a[2], b[2];
        rep(i, n) {
            int x;
            cin >> x;
            if (x < 0) a[0].push_back(-x);
            else a[1].push_back(x);
        }
        reverse(all(a[0]));
        rep(i, m) {
            int x;
            cin >> x;
            if (x < 0) b[0].push_back(-x);
            else b[1].push_back(x);
        }
        reverse(all(b[0]));
        int ans = 0;
        rep(z, 2) {
            int n = a[z].size(), m = b[z].size();
            int now = 0;
            {
                int j = 0;
                rep(i, n) {
                    while(j < m && b[z][j] < a[z][i]) j++;
                    if (j < m && b[z][j] == a[z][i]) {
                        now++;
                    }
                }
            }
            int mx = now;
            a[z].push_back(1001001001);
            b[z].push_back(1001001001);
            {
                int i = 0, j = 0, k = 0;
                int l = 0, r = 0;
                while(j < m) {
                    int d1 = a[z][i] - r, d2 = b[z][j] + 1 - r, d3 = b[z][k] + 1 - l;
                    int d = min({d1, d2, d3});
                    //cout << "before: " << l << ' ' << r << ' ' << j << ' ' << d1 << ' ' << d2 << ' ' << d3 << ' ' << now << endl;
                    l += d, r += d;
                    //cout << "after: " << l << ' ' << r << ' ' << d1 << ' ' << d2 << ' ' << d3 << ' ' << now << endl;
                    if (d == d2) {
                        j++;
                        now++;
                    }
                    if (d == d1) {
                        r++;
                        i++;
                        if (b[z][j] + 1 - r == 0) j++;
                    }
                    if (d == d3) {
                        k++;
                        now--;
                    }
                    //cout << now << endl;
                    chmax(mx, now);
                }
            }
            ans += mx;
        }
        cout << ans << '\n';
    }
}