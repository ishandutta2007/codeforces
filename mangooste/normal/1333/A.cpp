#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        if ((n * m) % 2 == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    cout << ((i + j) % 2 == 0 ? 'B' : 'W');
                 cout << '\n';
            }
        } else {
            cout << "B";
            for (int i = 1; i < m; i++)
                cout << (i % 2 == 0 ? 'W' : 'B');
            cout << '\n';
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < m; j++)
                    cout << ((i + j) % 2 == 0 ? 'W' : 'B');
                cout << '\n';
            }
        }
    }
}