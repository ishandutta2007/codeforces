#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
vector < ll > get_divs(ll x) {
    vector < ll > ans;
    for (int i = 1; 1LL * i * i <= x; i++) {
        if (x % i == 0) {
            ans.push_back(i);
            if (i != x / i) ans.push_back(x / i);
        }
    }
    return ans;
}
ll n, k;
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return (a + b);
}
signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    ll a, b;
    cin >> a >> b;
    vector < ll > vals1 = {a, k - a};
    vector < ll > vals2 = {b, k - b};
    vector < ll > vall;
    for (ll x : vals1) {
        for (ll y : vals2) {
            vall.push_back((y - x + k) % k);
        }
    }
    ll mn = 1LL * n * k;
    for (auto t : vall) {
        //cout << t << " hre" << endl;
        mn = min(mn, (ll)gcd(k, t));
    }
    ll mx = 0;
    auto dd = get_divs(1LL * n * k);
    for (auto t : dd) {
        for (auto v : vall) {
            if (v % gcd(k, t) != 0) continue;
            mx = max(mx, t);
        }
    }
    cout << (1LL * n * k) / mx << " " << (1LL * n * k) / mn;
    return 0;
}