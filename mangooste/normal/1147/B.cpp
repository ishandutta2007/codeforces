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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> start(m);
    for (auto &el : start) {
        cin >> el.first >> el.second;
        el.first--;
        el.second--;
        if (el.first > el.second) {
            swap(el.first, el.second);
        }
    }
    sort(all(start));
    // cout << "start = ";
    // for (auto &el : start) {
    //     cout << "(" << el.first + 1 << ' ' << el.second + 1 << ") ";
    // }
    // cout << '\n';
    Fun<bool(int)> Check = [&](int del) {
        // cout << "Check " << del << '\n';
        vector<pair<int, int>> cur = start;
        for (auto &el : cur) {
            el.first += del;
            el.second += del;
            if (el.first >= n) {
                el.first -= n;
            }
            if (el.second >= n) {
                el.second -= n;
            }
            if (el.first > el.second) {
                swap(el.first, el.second);
            }
        }
        sort(all(cur));
        // cout << "cur = ";
        // for (auto el : cur) {
        //     cout << "(" << el.first + 1 << ' ' << el.second + 1 << ") ";
        // }
        // cout << '\n';
        return (cur == start);
    };
    bool fnd = false;
    vector<int> is_prime(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i + i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && n % i == 0) {
            fnd |= Check(n / i);
        }
    }
    cout << (fnd ? "YES\n" : "NO\n");
}