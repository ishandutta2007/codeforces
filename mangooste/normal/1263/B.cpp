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
        vector<string> dct(n);
        set<string> already;
        for (auto &el : dct) {
            cin >> el;
            already.insert(el);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> cur;
            for (int j = i + 1; j < n; j++)
                if (dct[j] == dct[i])
                    cur.pb(j);
            int num = 0, pos = 0;
            for (auto el : cur) {
                while (true) {
                    if (pos == 10)
                        pos = 0, num++;
                    string maybe = dct[el];
                    maybe[num] = '0' + pos;
                    if (!already.count(maybe)) {
                        dct[el] = maybe;
                        already.insert(dct[el]);
                        break;
                    }
                    pos++;
                }
            }
            ans += cur.size();
        }
        cout << ans << '\n';
        for (auto el : dct)
            cout << el << '\n';
    }
}