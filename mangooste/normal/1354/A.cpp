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

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b >= a) {
        cout << b << '\n';
        return;
    }
    if (d >= c) {
        cout << "-1\n";
        return;
    }
    a -= b;
    ll del = c - d;
    ll cnt = (a + del - 1) / del;
    cout << cnt * c + b << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}