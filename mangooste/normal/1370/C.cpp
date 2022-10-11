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

void Main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "FastestFinger\n";
        } else if (n % 2 == 1 || n == 2) {
            cout << "Ashishgup\n";
        } else {
            int cnt = 0;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    if (i % 2 == 1) {
                        cnt++;
                    }
                    if (i * i != n && (n / i) % 2 == 1) {
                        cnt++;
                    }
                }
            }
            int two = 0;
            while (n % 2 == 0) {
                two++;
                n /= 2;
            }
            if (cnt == 0) {
                cout << "FastestFinger\n";
            } else if (two == 1) {    
                cout << (cnt > 1 ? "Ashishgup\n" : "FastestFinger\n");
            } else {
                cout << "Ashishgup\n";
            }
        }
    }
}