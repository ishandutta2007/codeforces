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
    int n;
    cin >> n;
    vector<int> a(n);
    int one = 0, zero = 0;
    for (auto &el : a) {
        cin >> el;
        one += (el == 1);
        zero += (el == 0);
    }
    for (int i = 0; i < n; i++) {
        one -= (a[i] == 1);
        zero -= (a[i] == 0);
        if (one == 0 || zero == 0)
            return cout << i + 1 << '\n', 0;
    }
}