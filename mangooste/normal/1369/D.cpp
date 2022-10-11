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

const ll MOD = 1e9 + 7;
const int N = 2'000'000 + 228;
ll prec[N];

void Main() {
    for (int i = 3; i < N; i++) {
        if (i % 3 == 0) {
            prec[i] = 1;
        }
        prec[i] += 2 * prec[i - 2];
        prec[i] += prec[i - 1];
        prec[i] %= MOD;
    }
    int t = 1;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << 4 * prec[n] % MOD << '\n';
    }
}