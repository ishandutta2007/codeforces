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
    Fun<int(int, int)> Ask = [&](int c, int d) {
        cout << "? " << c << ' ' << d << endl;
        int cur;
        cin >> cur;
        return cur;
    };
    int a = 0, b = 0;
    bool more = (Ask(0, 0) == -1);
    for (int bit = 29; bit >= 0; bit--) {
        int power = (1 << bit);
        int cur = Ask(a + power, b + power);
        if (!more) {
            if (cur == -1) {
                a += power;
                more = (Ask(a, b) == -1);
            } else {
                cur = Ask(a, b + power);
                if (cur > 0) {
                    a += power;
                    b += power;
                }
            }
        } else {
            if (cur == 1) {
                b += power;
                more = (Ask(a, b) == -1);
            } else {
                cur = Ask(a + power, b);
                if (cur < 0) {
                    a += power;
                    b += power;
                }
            }
        }
    }
    cout << "! " << a << ' ' << b << '\n';
}