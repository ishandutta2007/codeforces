#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;
map <ll, int> mp;
map <pll, int> same;

int main() {
    ll n, a, b, ans = 0;
    scanf("%lld %lld %lld", &n, &a, &b);
    for(int i = 0; i < n; i++) {
        ll x, vx, vy;
        scanf("%lld %lld %lld", &x, &vx, &vy);
        ll res = vy - a * vx;
        pll node = (pll){vx, vy};
        ans += mp[res] - same[node];
        mp[res]++;
        same[node]++;
    }
    printf("%lld\n", ans << 1);
    return 0;
}