#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
        ll x;
        cin >> x;
        if (x == 2) {
            cout << 3 << '\n';
            continue;
        }
        ll l = 0, r = x;
        while(r - l > 1) {
            ll c = (l + r) >> 1;
            if (c * (c + 1) / 2 >= x) r = c;
            else l = c;
        }
        cout << r + (r * (r + 1) / 2 - x == 1 ? 1 : 0) << '\n';
    }
}