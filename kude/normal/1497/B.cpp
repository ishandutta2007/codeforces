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
        VI hist(m);
        rep(i, n) {
            int x;
            cin >> x;
            hist[x % m]++;
        }
        int ans = 0;
        rep(i, m) {
            int j = m - i;
            if (i == 0) {
                ans += hist[i] != 0;
                continue;
            }
            if (i > j) break;
            if (i == j) {
                ans += hist[i] != 0;
                continue;
            }
            int ci = hist[i], cj = hist[j];
            if (ci > cj) swap(ci, cj);
            if (cj == 0) continue;
            if (ci == cj || ci + 1 == cj) {
                ans++;
                continue;
            }
            cj -= (ci + 1);
            ans += 1 + cj;
        }
        cout << ans << '\n';
    }
}