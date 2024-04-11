#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e6 + 10;
int A, B, C, D;
ll tot[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> A >> B >> C >> D;
    for (int sum = 0; sum < maxN; sum++) {
        if (sum < A + B) continue;
        int p = sum - A - B;
        int r1 = B - A;
        int r2 = C - B;
        if (r1 > r2) swap(r1, r2);
        if (p > r1 + r2) continue;
        int val = 0;
        if (p <= r1) {
            val = p + 1;
        }
        else if (p <= r2) {
            val = r1 + 1;
        }
        else {
            val = r1 + r2 + 1 - p;
        }
        tot[sum] += val;
    }
    ll g = 0;
    ll ans = 0;
    for (int i = maxN - 2; i >= 0; i--) {
        g += tot[i + 1];
        if (D >= i && i >= C) ans += g;
    }
    cout << ans;
    return 0;
}