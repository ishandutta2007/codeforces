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
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n && i <= a; i++) {
        if (n - i <= b) {
            ans++;
        }
    }
    cout << ans << '\n';
}