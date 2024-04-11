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
        int n, k;
        cin >> n >> k;
        VI ans(n, -1);
        int mx = (n - 1) / 2;
        if (k > mx) {
            cout << -1 << '\n';
            continue;
        }
        rep(i, k) ans[1 + 2 * i] = n - 1 - i;
        int t = 0;
        rep(i, n) if (ans[i] == -1) ans[i] = t++;
        rep(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
    }
}