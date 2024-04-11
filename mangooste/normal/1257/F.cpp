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

const int half = (1 << 15) - 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    map<vector<int>, int> left_part;
    for (int mask = 0; mask <= half; mask++) {
        vector<int> cur(n);
        for (int i = 0; i < n; i++) {
            int value = a[i];
            value >>= 15;
            value ^= mask;
            int all = __builtin_popcount(value);
            cur[i] = all;
        }
        vector<int> cur_deltas(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cur_deltas[i] = cur[i + 1] - cur[i];
        }
        left_part[cur_deltas] = mask;
    }
    for (int mask = 0; mask <= half; mask++) {
        vector<int> cur(n);
        for (int i = 0; i < n; i++) {
            int value = a[i];
            int left_bits = __builtin_popcount(value >> 15);
            value ^= mask;
            int all = __builtin_popcount(value) - left_bits;
            cur[i] = all;
        }
        vector<int> cur_deltas(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cur_deltas[i] = cur[i + 1] - cur[i];
        }
        vector<int> need = cur_deltas;
        for (auto &el : need) {
            el *= -1;
        }
        if (left_part.find(need) != left_part.end()) {
            cout << mask + (left_part[need] << 15) << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}