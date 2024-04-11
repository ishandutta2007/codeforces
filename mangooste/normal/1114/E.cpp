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
    int n;
    cin >> n;
    int Q = 60;
    int L = -1, R = 1'000'000'000;
    while (R - L > 1) {
        Q--;
        int mid = (L + R) / 2;
        cout << "> " << mid << endl;
        int cur;
        cin >> cur;
        if (cur) {
            L = mid;
        } else {
            R = mid;
        }
    }
    mt19937 rng;
    vector<int> inds(n);
    iota(inds.begin(), inds.end(), 0);
    shuffle(inds.begin(), inds.end(), rng);
    int g = 0;
    for (int i = 0; i < Q && i < n; i++) {
        cout << "? " << inds[i] + 1 << endl;
        int cur;
        cin >> cur;
        g = __gcd(g, R - cur);
    }
    cout << "! " << R - (n - 1) * g << ' ' << g << endl;
}