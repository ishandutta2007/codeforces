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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 3) {
            cout << "-1\n";
            continue;
        }
        if (n == 4) {
            cout << "3 1 4 2\n";
            continue;
        }
        vector<int> ans = {};
        vector<int> even, odd;
        for (int i = 0; i < n; i += 2)
            even.pb(i);
        for (int i = 1; i < n; i += 2)
            odd.pb(i);
        if (n % 2 == 1) {
            for (auto el : even)
                ans.pb(el);
            ans.pb(odd[odd.size() - 2]);
            ans.pb(odd[odd.size() - 1]);
            for (int i = odd.size() - 3; i >= 0; i--)
                ans.pb(odd[i]);
        } else {
            for (auto el : odd)
                ans.pb(el);
            ans.pb(even[even.size() - 2]);
            ans.pb(even[even.size() - 1]);
            for (int i = even.size() - 3; i >= 0; i--)
                ans.pb(even[i]);
        }
        for (auto el : ans)
            cout << el + 1 << ' ';
        cout << '\n';
    }
}