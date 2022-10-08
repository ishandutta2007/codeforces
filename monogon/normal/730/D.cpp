
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// each bridge either requires the drink or not
// greedily use drinks as late as possible so that we can still cross bridges
// can cross bridge in time 2 * s - (length when using drink)

const int N = 2e5 + 5;
int n;
ll r, l[N], t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r;
    rep(i, 1, n + 1) cin >> l[i];
    rep(i, 1, n + 1) cin >> t[i];
    ll k = 0;
    ll amtleft = 0, T = 0;
    vector<ll> ve;
    rep(i, 1, n + 1) {
        ll amt = 2 * l[i] - amtleft - t[i];
        if(amt <= 0) {
            T += 2 * l[i] - min(amtleft, l[i]);
            amtleft = max(0LL, amtleft - l[i]);
        }else if(amt > l[i]) {
            cout << "-1\n";
            return 0;
        }else {
            ll x = (amt + r - 1) / r;
            for(int j = 0; j < x && sz(ve) <= 100000; j++) {
                ve.push_back(T + 2 * l[i] - amtleft - amt - amt + r * j);
            }
            k += x;
            T += 2 * l[i] - amtleft - amt;
            amtleft = r * x - amt;
        }
    }
    cout << k << '\n';
    if(k <= 100000) {
        for(ll x : ve) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}