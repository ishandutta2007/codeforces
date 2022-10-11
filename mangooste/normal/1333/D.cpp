#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> ans;
    int cnt = 0;
    while (true) {
        ans.push_back({});
        bool fnd = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                ans.back().push_back(i + 1);
                fnd = true;
                cnt++;
            }
        }
        for (auto i : ans.back())
            swap(s[i - 1], s[i]);
        if (!fnd) {
            ans.pop_back();
            break;
        }
    }
    if (cnt < k || ans.size() > k)
        return cout << "-1\n", 0;
    for (int i = 0; i < ans.size(); i++) {
        while (ans.size() < k && ans[i].size() > 1) {
            cout << "1 " << ans[i].back() << '\n';
            ans[i].pop_back();
            k--;
        }
        cout << ans[i].size() << ' ';
        for (auto j : ans[i])
            cout << j << ' ';
        cout << '\n';
    }
}