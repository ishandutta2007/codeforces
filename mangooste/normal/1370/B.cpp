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

void Main();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Main();
#ifdef LOCAL
    cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

void Main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> odd, even;
        for (int i = 1; i <= 2 * n; i++) {
            int a;
            cin >> a;
            if (a % 2 == 0) {
                even.push_back(i);
            } else {
                odd.push_back(i);
            }
        }
        if ((int)odd.size() % 2 == 1) {
            // cout << odd.back() << ' ' << even.back() << '\n';
            odd.pop_back();
            even.pop_back();
        } else {
            if ((int)odd.size() >= 2) {
                // cout << odd.back() << ' ';
                odd.pop_back();
                // cout << odd.back() << '\n';
                odd.pop_back();
            } else {
                // cout << even.back() << ' ';
                even.pop_back();
                // cout << even.back() << '\n';
                even.pop_back();
            }
        }
        for (int i = 0; i < (int)odd.size(); i += 2) {
            cout << odd[i] << ' ' << odd[i + 1] << '\n';
        }
        for (int i = 0; i < (int)even.size(); i += 2) {
            cout << even[i] << ' ' << even[i + 1] << '\n';
        }
    }
}