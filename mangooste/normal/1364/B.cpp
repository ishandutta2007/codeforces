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

void solve_case() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &el : p) {
        cin >> el;
    }
    vector<int> answer;
    answer.push_back(p[0]);
    answer.push_back(p[1]);
    for (int i = 2; i < n; i++) {
        if (p[i] > answer.back()) {
            if (answer.back() > answer[answer.size() - 2]) {
                answer.back() = p[i];
            } else {
                answer.push_back(p[i]);
            }
        } else {
            if (answer.back() < answer[answer.size() - 2]) {
                answer.back() = p[i];
            } else {
                answer.push_back(p[i]);
            }
        }
    }
    cout << answer.size() << '\n';
    for (auto el : answer) {
        cout << el << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve_case();
    }
}