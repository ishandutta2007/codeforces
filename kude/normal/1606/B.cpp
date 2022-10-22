#include<bits/stdc++.h>
namespace {
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

} int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        ll n, k;
        cin >> n >> k;
        ll done = 1, undone = n - 1;
        ll ans = 0;
        while(undone) {
          if (done < k) {
            ans++;
            undone -= done;
            done *= 2;
          } else {
            ans += (undone + k - 1) / k;
            done = n;
            undone = 0;
          }
        }
        cout << ans << '\n';
    }
}