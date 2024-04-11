#include <algorithm>
#include <cmath>
#include <cstring>
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (auto &el : a)
        cin >> el;
    const int INF = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        int mn = INF;
        for (int j = i - x; j <= i + y; j++)
            if (i != j && j >= 0 && j < n)
                mn = min(mn, a[j]);
        if (mn > a[i])
            return cout << i + 1 << '\n', 0;
    }
}