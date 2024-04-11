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
        int n, q;
        cin >> n >> q;
        VI a(n);
        rep(i, n) {
            char c;
            cin >> c;
            if (i % 2) c ^= '+' ^ '-';
            a[i] = c == '+' ? 1 : -1;
        }
        VI ppos, npos;
        rep(i, n) {
            if (a[i] == 1) ppos.push_back(i);
            else npos.push_back(i);
        }
        VI s(n + 1);
        rep(i, n) s[i + 1] = s[i] + a[i];
        while(q--) {
            int l, r;
            cin >> l >> r;
            l--;
            int d = s[r] - s[l];
            bool flip = d < 0;
            if (flip) {
                swap(npos, ppos);
                d = -d;
            }
            if (d % 2) {
                cout << 1 << '\n';
            } else {
                if (d == 0) cout << 0 << '\n';
                else cout << 2 << '\n';
            }
            // VI ans;
            // int b = lower_bound(all(ppos), l) - ppos.begin();
            // rep(i, d) ans.push_back(ppos[b + i]);
            // cout << d << '\n';
            // rep(i, d) cout << ans[i] + 1 << " \n"[i + 1 == d];
            if (flip) {
                swap(npos, ppos);
            }
        }
    }
}