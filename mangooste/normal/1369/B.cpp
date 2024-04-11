#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Main();
#ifdef LOCAL
    cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

void Main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int L = 0, R = n - 1;
        while (R >= 0 && s[R] == '1') {
            R--;
        }
        while (L < n && s[L] == '0') {
            L++;
        }
        for (int i = 0; i < L; i++) {
            cout << '0';
        }
        if (L != R + 1) {
            cout << '0';
        }
        for (int i = R + 1; i < n; i++) {
            cout << '1';
        }
        cout << '\n';
    }
}