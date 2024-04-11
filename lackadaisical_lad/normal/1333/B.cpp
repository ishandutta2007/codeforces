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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& i : a) {
            cin >> i;
        }
        for (int& i : b) {
            cin >> i;
        }
        bool ok = a[0] == b[0];
        bool pos = a[0] == 1;
        bool neg = a[0] == -1;
        for (int i = 1; i < n; i++) {
            int kek = b[i] - a[i];
            if (kek > 0 && !pos) {
                ok = false;
                break;
            }
            if (kek < 0 && !neg) {
                ok = false;
                break;
            }
            pos |= a[i] == 1;
            neg |= a[i] == -1;
        }
        cout << vector<string>{ "NO", "YES" }[ok] << '\n';
    }
    return 0;
}