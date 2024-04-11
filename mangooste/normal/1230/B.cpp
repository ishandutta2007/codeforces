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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0) return cout << s << '\n', 0;
    if (n == 1) return cout << "0\n", 0;
    if (s[0] != '1') k--, s[0] = '1';
    for (int i = 1; i < n && k; i++)
        if (s[i] != '0') k--, s[i] = '0';
    cout << s;
}