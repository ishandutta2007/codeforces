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
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    int mn = *min_element(all(a));
    int cnt = 0;
    for (auto el : a) {
        if (el == mn) {
            cnt++;
        }
    }
    if (cnt * 2 > n) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}