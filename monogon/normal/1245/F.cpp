
#include <bits/stdc++.h>

#define ll long long
using namespace std;

map<tuple<ll, ll, int>, ll> ma;

ll solve(ll r1, ll r2, int bit) {
    if(ma.count(make_tuple(r1, r2, bit))) {
        return ma[make_tuple(r1, r2, bit)];
    }
    auto &dp = ma[make_tuple(r1, r2, bit)];
    if(bit < 0) return dp = 1;
    bool b1 = ((r1 >> bit) & 1);
    bool b2 = ((r2 >> bit) & 1);
    // 0 0
    ll ans = solve(b1 ? -1 : r1, b2 ? -1 : r2, bit - 1);
    if(b1) {
        // 1 0
        ans += solve(r1, b2 ? -1 : r2, bit - 1);
    }
    if(b2) {
        // 0 1
        ans += solve(b1 ? -1 : r1, r2, bit - 1);
    }
    return dp = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        ll l, r;
        cin >> l >> r;
        ll ans = 0;
        if(l == 0) {
            ans = solve(r, r, 30);
        }else {
            ans = solve(r, r, 30) - solve(l - 1, r, 30) - solve(r, l - 1, 30) + solve(l - 1, l - 1, 30);
        }
        cout << ans << '\n';
    }
}