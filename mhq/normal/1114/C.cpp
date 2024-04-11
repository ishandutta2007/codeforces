#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, b;
vector < pair < ll, int > > factor(ll b) {
    vector < pair < ll, int > > cur;
    for (int i = 2; 1LL * i * i <= b; i++) {
        if (b % i == 0) {
            int exp = 0;
            while (b % i == 0) {
                b /= i;
                exp++;
            }
            cur.emplace_back(i, exp);
        }
    }
    if (b > 1) {
        cur.emplace_back(b, 1);
    }
    return cur;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> b;
    auto fct = factor(b);
    ll ans = (ll)1e18;
    for (auto t : fct) {
        ll p = t.first;
        ll need = t.second;
        ll cop = n;
        ll cur = 0;
        while (cop > 0) {
            cur += cop / p;
            cop /= p;
        }
        ans = min(ans, cur / need);
    }
    cout << ans;
}