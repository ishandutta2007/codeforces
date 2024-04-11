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
        VI a(n);
        rep(i, n) cin >> a[i], a[i] %= 2;
        int ocnt = 0, ecnt = 0;
        rep(i, n) ocnt += a[i];
        ecnt = n - ocnt;
        constexpr ll INF = 1e18;
        ll ans = INF;
        rep(_, 2) {
            if (n % 2 == 0 && ecnt == ocnt || n % 2 == 1 && ecnt == ocnt + 1) {
                int p = 0;
                ll cnt = 0;
                for(int i = 0; i < n; i += 2) {
                    while(a[p]) p++;
                    cnt += abs(p - i);
                    p++;
                }
                chmin(ans, cnt);
            }
            rep(i, n) a[i] ^= 1;
            swap(ecnt, ocnt);
        }
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }
}