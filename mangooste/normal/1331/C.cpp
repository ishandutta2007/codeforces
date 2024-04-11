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
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int a;
    cin >> a;
    vector<int> num = { 4, 1, 3, 2, 0, 5 };
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        int bit = ((a >> i) & 1);
        if (bit == 0)
            continue;
        ans += (1 << num[i]);
    }
    cout << ans << '\n';
}