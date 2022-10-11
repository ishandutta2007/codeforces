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

int n;
#define left left228
#define right right228
vector<int> p, left, right, where;

vector<int> get(vector<int> &a) {
    vector<int> ans(n);
    vector<pair<int, int>> stack;
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && stack.back().first < a[i]) {
            stack.pop_back();
        }
        if (stack.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = stack.back().second;
        }
        stack.emplace_back(a[i], i);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    p.resize(n);
    for (auto &el : p) {
        cin >> el;
    }
    where.resize(n + 1);
    where[0] = -1;
    for (int i = 0; i < n; i++) {
        where[p[i]] = i;
    }
    left = get(p);
    reverse(p.begin(), p.end());
    right = get(p);
    reverse(p.begin(), p.end());
    reverse(right.begin(), right.end());
    for (auto &el : right) {
        el = n - 1 - el;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int L = left[i] + 1;
        int R = right[i] - 1;
        if (i - L < R - i) {
            for (int j = L; j <= i; j++) {
                int need = p[i] - p[j];
                if (need <= n) {
                    if (i <= where[need] && where[need] <= R) {
                        ans++;
                    }
                }
            }
        } else {
            for (int j = i; j <= R; j++) {
                int need = p[i] - p[j];
                if (need <= n) {
                    if (L <= where[need] && where[need] <= i) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}