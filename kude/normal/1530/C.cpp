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
        VI a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        sort(all(a)), sort(all(b));
        int la = n / 4, lb = n / 4;
        int now_a = 0, now_b = 0;
        for(int i = la; i < n; i++) now_a += a[i];
        for(int i = lb; i < n; i++) now_b += b[i];
        int ans = 0;
        int len = n;
        while(now_a < now_b) {
            ans++;
            now_a += 100;
            len++;
            if (len % 4 == 0) {
                if (la < n) now_a -= a[la++];
            } else {
                if (lb) now_b += b[--lb];
            }
        }
        cout << ans << '\n';
    }
}