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

//#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0, last = 0;
        for (int i = 0; i < n; i++) if (s[i] == 'R') ans = max(ans, i + 1 - last), last = i + 1;
        ans = max(ans, n + 1 - last);
        cout << ans << '\n';
    }
}