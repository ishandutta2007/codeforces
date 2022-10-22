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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;

        int hist[32] = {};
        rep(_, n) {
            int x = 0;
            rep(i, 5) {
                int b;
                cin >> b;
                x |= b << i;
            }
            hist[x]++;
        }
        rep(k, 5) rep(s, 32) if (s >> k & 1) hist[s ^ 1 << k] += hist[s];
        bool ok = false;
        rep(i, 5) rep(j, i) {
            int c1 = hist[1 << i];
            int c2 = hist[1 << j];
            int c12 = hist[1 << i | 1 << j];
            if (c1 + c2 - c12 != n) continue;
            c1 -= c12, c2 -= c12;
            if (c1 <= n / 2 && c2 <= n / 2) ok = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}