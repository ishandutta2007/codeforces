#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &el : a) {
            cin >> el;
        }
        for (auto &el : b) {
            cin >> el;
        }
        if (n % 2 && a[n / 2] != b[n / 2]) {
            cout << "NO\n";
            continue;
        }
        vector<pair<int, int>> pa;
        for (int i = 0; i < n / 2; i++) {
            pair<int, int> cur = make_pair(a[i], a[n - 1 - i]);
            if (cur.first > cur.second) {
                swap(cur.first, cur.second);
            }
            pa.push_back(cur);
        }
        vector<pair<int, int>> pb;
        for (int i = 0; i < n / 2; i++) {
            pair<int, int> cur = make_pair(b[i], b[n - 1 - i]);
            if (cur.first > cur.second) {
                swap(cur.first, cur.second);
            }
            pb.push_back(cur);
        }
        sort(pa.begin(), pa.end());
        sort(pb.begin(), pb.end());
        cout << (pa == pb ? "YES\n" : "NO\n");
    }
}