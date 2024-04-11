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
    vector<int> k(n);
    for (auto &el : k) {
        cin >> el;
    }
    vector<vector<int>> when(n);
    for (int i = 0; i < m; i++) {
        int d, v;
        cin >> d >> v;
        v--;
        when[v].pb(d);
    }
    for (auto &el : when) {
        sort(all(el));
        el.resize(unique(all(el)) - el.begin());
    }
    Fun<bool(int)> check = [&](int num) {
        vector<vector<int>> maybe(num);
        int need = 0;
        for (int i = 0; i < n; i++) {
            if (k[i] != 0) {
                int pos = upper_bound(all(when[i]), num) - when[i].begin() - 1;
                if (pos >= 0) {
                    maybe[when[i][pos] - 1].pb(k[i]);
                } else {
                    need += 2 * k[i];
                }
            }
        }
        int balance = 0;
        for (int i = 0; i < num; i++) {
            balance++;
            while (!maybe[i].empty() && balance > 0) {
                int bk = maybe[i].back();
                if (balance >= bk) {
                    maybe[i].pop_back();
                    balance -= bk;
                } else {
                    maybe[i].back() -= balance;
                    balance = 0;
                }
            }
            need += accumulate(all(maybe[i]), 0) * 2;
        }
        return balance >= need;
    };
    int L = 0, R = 2 * accumulate(all(k), 0);
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    cout << R << '\n';
}