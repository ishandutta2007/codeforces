#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <bitset>
#include <queue>
#include <random>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < n - 1 || j < m - 1) {
                    cout << 'B';
                } else {
                    cout << 'W';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}