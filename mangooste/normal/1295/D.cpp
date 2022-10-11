#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

ll gcd(ll a, ll b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll phi(ll a) {
    ll start = a;
    ll ans = a;
    for (ll i = 2; i * i <= start; i++) {
        if (a % i)
            continue;
        while (a % i == 0)
            a /= i;
        ans /= i;
        ans *= i - 1;
    }
    if (a != 1) {
        ans /= a;
        ans *= a - 1;
    }
    return ans;
}

void solve() {
    ll a, m;
    cin >> a >> m;
    ll g = gcd(a, m);
    cout << phi(m / g) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}