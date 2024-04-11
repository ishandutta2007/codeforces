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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> right(n);
    right[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
        right[i] = (a[i] == a[i + 1] ? right[i + 1] : i);
    int A, B, C;
    A = B = C = 0;
    int mid = 0;
    while (2 * (right[mid] + 1) <= n)
        mid++;
    mid--;
    for (int i = 0; 2 * ((i + 1) + 2 * (i + 2)) <= n; i++) {
        if (a[i] == a[i + 1])
            continue;
        if (2 * (i + 1) >= n)
            continue;
        int j = right[2 * (i + 1)];
        if (j + i + 2 >= n)
            continue;
        if (j >= mid)
            continue;
        int cur_a = i + 1;
        int cur_b = j - i;
        int cur_c = mid - j;
        if (cur_a >= cur_b || cur_a >= cur_c)
            continue;
        if (cur_a + cur_b + cur_c >= A + B + C)
            A = cur_a, B = cur_b, C = cur_c;
    }
    cout << A << ' ' << B << ' ' << C << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}