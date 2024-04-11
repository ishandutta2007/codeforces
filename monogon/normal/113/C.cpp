
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

const int N = 300'000'005;
bitset<N> comp;
ll l, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> l >> r;
    comp.set(1, true);
    for(ll p = 2; p <= r; p++) {
        if(!comp[p]) {
            for(ll k = p * p; k <= r; k += p) {
                comp.set(k, true);
            }
        }
    }
    ll ans = 0;
    if(l <= 2 && 2 <= r) ans++;
    while((l % 4) != 1) l++;
    while((r % 4) != 1) r--;
    for(ll i = l; i <= r; i += 4) {
        ans += !comp[i];
    }
    cout << ans << '\n';
}