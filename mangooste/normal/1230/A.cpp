#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <iomanip>

using ll = long long;
using namespace std;

// #define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    vector<int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(all(a));
    if (a[0] + a[2] == a[1] + a[3] || a[0] + a[3] == a[1] + a[2] || a[3] == a[0] + a[1] + a[2])
        cout << "YES\n";
    else
        cout << "NO\n";
}