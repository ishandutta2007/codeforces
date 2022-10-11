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
    int t;
    cin >> t;
    while (t--) {
        ll A, B;
        cin >> A >> B;
        ll p = 10, ans = 0;
        while (p - 1 <= B) {
            ans += A;
            p *= 10;
        }
        cout << ans << "\n";
    }
}