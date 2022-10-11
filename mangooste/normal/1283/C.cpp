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

int n;
vector<int> a;
vector<char> need;

void Main() {
    cin >> n;
    a.resize(n);
    need.resize(n, 1);
    for (auto &el : a) {
        cin >> el;
        if (el > 0) {
            need[el - 1] = 0;
        }
        el--;
    }
    vector<int> bad, ok;
    for (int i = 0; i < n; i++) {
        if (need[i]) {
            bad.push_back(i);
        }
        if (a[i] == -1) {
            ok.push_back(i);
        }
    }
    for (int i = 0; i < (int)bad.size(); i++) {
        if (bad[i] == ok[i] || (i + 2 == (int)bad.size() && bad[i + 1] == ok[i + 1])) {
            swap(ok[i], ok[i + 1]);
        }
        a[ok[i]] = bad[i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << ' ';
    }
    cout << '\n';
}