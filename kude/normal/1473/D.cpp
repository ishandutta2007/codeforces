#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
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
        VI a(n);
        string st;
        cin >> st;
        rep(i, n) {
            a[i] = (st[i] == '+' ? 1 : -1);
        }
        VI s(n + 1);
        rep(i, n) s[i + 1] = s[i] + a[i];
        VI mx_f(n + 1), mn_f(n + 1);
        {
            int mx = 0, mn = 0;
            rep(i, n + 1) {
                chmax(mx, s[i]);
                chmin(mn, s[i]);
                mx_f[i] = mx;
                mn_f[i] = mn;
            }
        }
        VI mx_b(n + 1),mn_b(n + 1);
        {
            int mx = 0, mn = 0;
            rrep(i, n + 1) {
                chmax(mx, s[i] - s[n]);
                chmin(mn, s[i] - s[n]);
                mx_b[i] = mx;
                mn_b[i] = mn;
            }
        }
        while(m--) {
            int l, r;
            cin >> l >> r;
            --l;
            int mx = max(mx_f[l], s[n] - (s[r] - s[l]) + mx_b[r]);
            int mn = min(mn_f[l], s[n] - (s[r] - s[l]) + mn_b[r]);
            cout << mx - mn + 1 << '\n';
        }
    }
}