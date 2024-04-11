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
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    k = r - k;
    r = r - l;
    if (x < y) {
        if (k >= y) {
            k -= y;
            ll d = y - x;
            ll m = k / d;
            k -= m * d;
            k += x;
            t -= m + 1;
        }
        vector<bool> seen(x + 10, false);
        bool ok = true;
        while(t > 0) {
            ll m = (y - k + x - 1) / x;
            if (t <= m) {
                k += t * x;
                if (k > r) ok = false;
                break;
            }
            k += m * x;
            t -= m;
            if (k > r) {
                ok = false;
                break;
            }
            k -= y;
            if (seen[k]) break;
            seen[k] = true;
            k += x;
            t -= 1;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    } else {
        if (k >= y) k -= y;
        k += x;
        t -= 1;
        __int128 ti = t, ki = k;
        ki += ti * (x - y);
        if (ki <= r) cout << "Yes\n";
        else cout << "No\n";
    }
}