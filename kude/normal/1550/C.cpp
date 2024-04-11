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
        int ans = 0;
        VI a(n);
        rep(i, n) cin >> a[i];
        rep(i, n) {
            ans++;
            if (i - 1 >= 0) ans++;
            if (i - 2 >= 0) {
                if (!(a[i-2] <= a[i-1] && a[i-1] <= a[i]) && !(a[i-2] >= a[i-1] && a[i-1] >= a[i])) {
                    ans++;
                }
            }
            if (i - 3 >= 0) {
                bool ok = true;
                for(int i1 = i - 3; i1 <= i; i1++) for(int i2 = i1 + 1; i2 <= i; i2++) for(int i3 = i2 + 1; i3 <= i; i3++) {
                    if (a[i1] <= a[i2] && a[i2] <= a[i3] || a[i1] >= a[i2] && a[i2] >= a[i3]) ok = false;
                }
                ans += ok;
            }
        }
        cout << ans << '\n';
    }
}