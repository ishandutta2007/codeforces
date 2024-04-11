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
        int mn = 1001001001, mx = -1, imn = -1, imx = -1;
        rep(i, n) {
            int a;
            cin >> a;
            if (a < mn) {
                mn = a, imn = i;
            }
            if (a > mx) {
                mx = a, imx = i;
            }
        }
        int ans = min({max(imx, imn) + 1, n - min(imn, imx), imx + 1 + n - imn, imn + 1 + n - imx});
        cout << ans << '\n';
    }
}