#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll all = n * (n + 1) / 2ll;
        ll zero = n - m;
        ll cnt = m + 1;
        ll mn = zero / cnt;
        ll ost = zero - cnt * mn;
        ll a = mn * (mn + 1) / 2ll;
        ll b = (mn + 1) * (mn + 2) / 2ll;
        ll ans = all - a * (m + 1 - ost) - b * ost;
        cout << ans << '\n';
    }
}