#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

const ll MOD = 998244353LL;

void mult(ll& a, ll b) {
    a *= b;
    a %= MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    if (n == 1)
        return cout << "1 1\n", 0;
    ll mx = 0;
    for (ll i = n; i > n - k; i--)
        mx += i;
    vector<int> pos;
    for (int i = 0; i < n; i++)
        if (a[i] > n - k)
            pos.push_back(i);
    ll ans = 1;
    for (int i = 1; i < pos.size(); i++) {
        ll del = pos[i] - pos[i - 1];
        mult(ans, del);
    }
    cout << mx << ' ' << ans << '\n';
}