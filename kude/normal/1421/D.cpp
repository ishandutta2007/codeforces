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
        ll x, y;
        cin >> x >> y;
        ll c1, c2, c3, c4, c5, c6;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
        ll ans = 2002003004005006007;
        auto f = [&](ll p, ll q, ll c, ll d) {
            if (p >= 0 && q >= 0) chmin(ans, p*c+q*d);
            return;
        };
        // (1,1), (0,1)
        f(x,y-x,c1,c2);
        // (1,1), (-1,0)
        f(y,y-x,c1,c3);
        // (1,1), (0,-1)
        f(x,x-y,c1,c5);
        // (1,1), (1,0)
        f(y,x-y,c1,c6);
        // (0,1), (-1,0)
        f(y,-x,c2,c3);
        // (0,1),(-1,-1)
        f(y-x,-x,c2,c4);
        // (0,1),(1,0)
        f(y,x,c2,c6);
        // (-1,0),(-1,-1)
        f(y-x,-y,c3,c4);
        // (-1,0), (0, -1)
        f(-x,-y,c3,c5);
        // (-1,-1), (0,-1)
        f(-x,x-y,c4,c5);
        // (-1,-1), (1,0)
        f(-y,x-y,c4,c6);
        // (0,-1), (1,0)
        f(-y,x,c5,c6);
        cout << ans << '\n';
    }
}