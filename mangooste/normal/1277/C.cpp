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
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = s.size();
        int pos = 0;
        vector<int> ans;
        while (pos < n - 2) {
            if (pos + 4 < n && s.substr(pos, 5) == "twone") {
                ans.push_back(pos + 2);
                pos += 5;
            } else if (s.substr(pos, 3) == "one" || s.substr(pos, 3) == "two") {
                ans.push_back(pos + 1);
                pos += 3;
            } else
                pos++;
        }
        cout << ans.size() << '\n';
        for (int i : ans)
            cout << i + 1 << ' ';
        cout << '\n';
    }
}