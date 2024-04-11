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
        rep(i, n) cin >> a[i];
        ll ans = 0;
        VL cnt(n);
        rep(i, n) {
            if (cnt[i] < a[i] - 1) {
                ans += a[i] - 1 - cnt[i];
                cnt[i] = a[i] - 1;
            }
            for(int j = i + 2; j <= min(n - 1, i + a[i]); j++) {
                cnt[j]++;
            }
            if (i + 1 < n) {
                ll r = cnt[i] - (a[i] - 1);
                cnt[i+1] += r;
            }
        }
        cout << ans << '\n';
    }
}