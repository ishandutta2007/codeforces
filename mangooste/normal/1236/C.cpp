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
    int n;
    cin >> n;
    vector<vector<int>> ans(n);
    int j = 0;
    int d = 1;
    for (int i = 1; i <= n * n; i++) {
        if (j == n)
            j = n - 1, d = -1;
        else if (j == -1)
            j = 0, d = 1;
        ans[j].pb(i);
        j += d;
    }
    for (auto i : ans) {
        for (auto el : i)
            cout << el << ' ';
        cout << '\n';
    }
}