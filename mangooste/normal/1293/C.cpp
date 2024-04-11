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
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    vector<array<int, 2>> a(n, {0, 0});
    while (q--) {
        int r, c;
        cin >> c >> r, r--, c--;
        int cc = (c + 1) % 2;
        for (int i = r - 1; i <= r + 1; i++)
            if (i >= 0 && i < n && a[i][cc] && a[r][c])
                cnt--;
        a[r][c] ^= 1;
        for (int i = r - 1; i <= r + 1; i++)
            if (i >= 0 && i < n && a[i][cc] && a[r][c])
                cnt++;
        cout << (cnt == 0 ? "Yes\n" : "No\n");
    }
}