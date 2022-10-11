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
    int a1, a2, b1, b2, n;
    cin >> a1 >> a2 >> b1 >> b2 >> n;
    cout << max(0, n - a1 * (b1 - 1) - a2 * (b2 - 1)) << ' ';
    if (b1 > b2)
        swap(b1, b2), swap(a1, a2);
    if (b1 * a1 < n)
        cout << a1 + ((n - a1 * b1) / b2) << '\n';
    else
        cout << (n / b1) << '\n';
}