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
string s, t;

void GG() {
    int a = 0;
    for (auto el : s) {
        a += (el - '0');
    }
    int b = 0;
    for (auto el : t) {
        b += (el - '0');
    }
    if (a != b) {
        cout << "-1\n";
        exit(0);
    }
}

void Main() {
    cin >> n >> s >> t;
    GG();
    string a = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            a.push_back(s[i]);
        }
    }
    if (a.empty()) {
        cout << "0\n";
        return;
    }
    int where = -1;
    for (int i = 0; i < (int)a.size(); i++) {
        int j = i - 1;
        if (j < 0) {
            j += (int)a.size();
        }
        if (a[i] != a[j]) {
            where = i;
            break;
        }
    }
    assert(where != -1);
    string new_a = "";
    for (int i = where; i < (int)a.size(); i++) {
        new_a.push_back(a[i]);
    }
    for (int i = 0; i < where; i++) {
        new_a.push_back(a[i]);
    }
    a = new_a;
    assert(a[0] != a.back());
    int min_bal = 0, max_bal = 0, cur_bal = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        cur_bal += (a[i] == '1' ? 1 : -1);
        min_bal = min(min_bal, cur_bal);
        max_bal = max(max_bal, cur_bal);
    }
    cout << max_bal - min_bal << '\n';
}