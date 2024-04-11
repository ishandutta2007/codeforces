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
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, z;
    cin >> n >> z;
    vector<int> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    sort(all(a));
    Fun<bool(int)> check = [&](int val) {
        if (val * 2 > n) {
            return false;
        }
        for (int i = 0; i < val; i++) {
            if (a[n - val + i] - a[i] < z) {
                return false;
            }
        }
        return true;
    };
    int L = 0, R = n / 2 + 1;
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            L = mid;
        } else {
            R = mid;
        }
    }
    cout << L << '\n';
}