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
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool ok = false;
        rep(s, 1 << 4) {
            {
                int cnt = u;
                cnt -= s >> 0 & 1;
                cnt -= s >> 1 & 1;
                if (!(0 <= cnt && cnt <= n - 2)) continue;
            }
            {
                int cnt = r;
                cnt -= s >> 1 & 1;
                cnt -= s >> 2 & 1;
                if (!(0 <= cnt && cnt <= n - 2)) continue;
            }
            {
                int cnt = d;
                cnt -= s >> 2 & 1;
                cnt -= s >> 3 & 1;
                if (!(0 <= cnt && cnt <= n - 2)) continue;
            }
            {
                int cnt = l;
                cnt -= s >> 3 & 1;
                cnt -= s >> 0 & 1;
                if (!(0 <= cnt && cnt <= n - 2)) continue;
            }
            ok = true;
            break;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}