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

const int MOD = 998244353;

int mult(int a, int b) {
    return 1ll * a * b % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &el : a) {
        cin >> el;
    }
    for (auto &el : b) {
        cin >> el;
    }
    assert(is_sorted(b.begin(), b.end()));
    bool zero = false;
    zero |= (*min_element(a.begin(), a.end()) != b[0]);
    map<int, int> ind;
    for (int i = 0; i < m; i++) {
        ind[b[i]] = i;
    }
    vector<int> where(m, -1);
    for (int i = 0; i < n; i++) {
        if (ind.count(a[i])) {
            where[ind[a[i]]] = i;
        }
    }
    zero |= (*min_element(where.begin(), where.end()) == -1);
    vector<int> suffix_min(n + 1);
    suffix_min[n] = *max_element(a.begin(), a.end()) + 228;
    for (int i = n - 1; i >= 0; i--) {
        suffix_min[i] = min(suffix_min[i + 1], a[i]);
    }
    zero |= (!is_sorted(where.begin(), where.end()));
    for (int i = 0; i < m; i++) {
        zero |= (suffix_min[where[i]] < b[i]);
    }
    if (zero) {
        cout << "0\n";
        return 0;
    }
    int answer = 1;
    vector<int> stack, min_left(n, -1);
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && a[stack.back()] >= a[i]) {
            stack.pop_back();
        }
        if (!stack.empty()) {
            min_left[i] = stack.back();
        }
        stack.push_back(i);
    }
    for (int i = 1; i < m; i++) {
        assert(min_left[where[i]] != -1);
        answer = mult(answer, where[i] - min_left[where[i]]);
    }
    cout << answer << '\n';
}