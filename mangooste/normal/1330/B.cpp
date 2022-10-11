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

const int N = 2e5 + 1;
int a[N];
int cnt_left[N], cnt_right[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        fill(cnt_left, cnt_left + n + 1, 0);
        fill(cnt_right, cnt_right + n + 1, 0);

        for (int i = 0; i < n; i++)
            cnt_right[a[i]]++;

        set<int> left, right;
        for (int i = 1; i <= n; i++) {
            left.insert(i);
            if (cnt_right[i] == 0)
                right.insert(i);
        }

        vector<pair<int, int>> ans;

        for (int i = 0; i < n - 1; i++) {
            if (cnt_left[a[i]]++ == 0)
                left.erase(a[i]);
            if (--cnt_right[a[i]] == 0)
                right.insert(a[i]);
            if (*left.begin() == i + 2 && *right.begin() == n - i)
                ans.emplace_back(i + 1, n - i - 1);
        }

        cout << ans.size() << '\n';
        for (auto i : ans)
            cout << i.first << ' ' << i.second << '\n';
    }
}