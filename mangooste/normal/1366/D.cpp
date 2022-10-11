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
 
const int N = 10000000 + 228;
pair<int, int> erat[N];
 
void precalc() {
    fill(erat, erat + N, make_pair(-1, -1));
    for (int i = 2; i < N; i++) {
        if (erat[i] == make_pair(-1, -1)) {
            for (int j = i * 2; j < N; j += i) {
                if (erat[j].first == -1) {
                    erat[j].first = i;
                } else if (erat[j].second == -1) {
                    erat[j].second = i;
                }
            }
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    precalc();
    int n;
    cin >> n;
    vector<pair<int, int>> answer(n, make_pair(-1, -1));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            while (a % 2 == 0) {
                a /= 2;
            }
            if (a != 1) {
                answer[i] = make_pair(2, a);
            }
        } else {
            if (erat[a].second != -1) {
                answer[i] = erat[a];
            }
        }
    }
    for (auto el : answer) {
        cout << el.first << ' ';
    }
    cout << '\n';
    for (auto el : answer) {
        cout << el.second << ' ';
    }
    cout << '\n';
}