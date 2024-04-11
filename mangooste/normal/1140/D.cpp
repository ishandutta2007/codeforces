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
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 3; i <= n; i++)
        ans += i * (i - 1);
    cout << ans << '\n';
}