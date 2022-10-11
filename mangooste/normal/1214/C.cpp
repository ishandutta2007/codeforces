#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> bal(n + 1, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            bal[i + 1] = bal[i] + 1;
        } else {
            bal[i + 1] = bal[i] - 1;
        }
        if (bal[i + 1] < 0) {
            cnt++;
        }
    }
    int mn = *min_element(all(bal));
    if (mn >= -1 && bal[n] == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}