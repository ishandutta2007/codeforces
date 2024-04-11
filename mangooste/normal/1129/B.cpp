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
    int k;
    cin >> k;
    const int MAX_A = 1000000;
    bool fnd = false;
    for (int cnt = 3; cnt <= 1998 && !fnd; cnt++) {
        int sum = k + cnt;
        if ((cnt - 1) * sum <= cnt * (sum - 1) && sum - 1 <= MAX_A * (cnt - 2)) {
            fnd = true;
            cout << cnt << '\n';
            cout << "-1 1 ";
            sum--;
            cnt -= 2;
            while (sum >= MAX_A) {
                cnt--;
                sum -= MAX_A;
                cout << MAX_A << ' ';
            }
            if (sum != 0) {
                cnt--;
                cout << sum << ' ';
            }
            for (int i = 0; i < cnt; i++) {
                cout << "0 ";
            }
            cout << '\n';
        }
    }
    assert(fnd);
}