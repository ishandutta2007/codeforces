#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a - b * c > 0) {
            cout << -1 << '\n';
            continue;
        }
        ll ttt = a / b, anum = ttt / d + 1;
        ll ans = anum * a - (anum - 1) * anum / 2 * d * b;
        //cout << ttt << ' ' << anum << endl;
        //cout << anum * a << ' ' << (anum - 1) * anum / 2 << endl;
        cout << ans << '\n';
        //return 0;
    }
}