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
    string s;
    cin >> s;
    int n = s.size();
    int zero = 1, one = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cout << one << " 2\n";
            one++;
            if (one == 5)
                one = 1;
        } else {
            cout << zero << " 1\n";
            zero += 2;
            if (zero == 5)
                zero = 1;
        }
    }
}