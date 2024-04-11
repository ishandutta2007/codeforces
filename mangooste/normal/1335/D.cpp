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

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

const int n = 9;

void solve() {
    vector<vector<int>> table(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char cur;
            cin >> cur;
            cur -= '0';
            table[i][j] = cur;
        }
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        table[i][j] = table[i][j] % 9 + 1;
        j += 3 + (i % 3 == 2);
        j %= n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << table[i][j];
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}