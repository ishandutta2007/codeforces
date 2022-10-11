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

bool is_pal(string& s, int L, int R) {
    if (L < 0 || R >= s.size())
        return false;
    int len = R - L + 1;
    for (int i = 0; i <= len / 2; i++)
        if (s[L + i] != s[R - i])
            return false;
    return true;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (is_pal(s, 0, n - 1)) {
        cout << s << '\n';
        return;
    }
    int mx = 0;
    for (int i = 0; i < n - 1 - i; i++) {
        if (s[i] != s[n - 1 - i]) {
            mx = i;
            break;
        }
    }
    int left = 0;
    for (int i = mx; i < n - mx; i++)
        if (is_pal(s, mx, i))
            left = i - mx + 1;
    int right = 0;
    for (int i = n - mx - 1; i >= mx; i--)
        if (is_pal(s, i, n - 1 - mx))
            right = n - 1 - mx - i + 1;
    cerr << "ans: ";
    if (left >= right) {
        for (int i = 0; i < mx; i++)
            cout << s[i];
        for (int i = mx; i <= mx + left - 1; i++)
            cout << s[i];
        for (int i = n - mx; i < n; i++)
            cout << s[i];
    } else {
        for (int i = 0; i < mx; i++)
            cout << s[i];
        for (int i = n - 1 - mx - right + 1; i < n; i++)
            cout << s[i];
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
}