#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int mod;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 4e6 + 10;
int pref[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> mod;
    int cur_sum = 0;
    int last = -1;
    for (int i = 1; i <= n; i++) {
        pref[i] = sum(pref[i], pref[i - 1]);
        int dp_val = sum(cur_sum, pref[i]);
        if (i == 1) dp_val = 1;
        last = dp_val;
        for (int j = 2 * i; j <= n; j += i) {
            pref[j] = sum(pref[j], dp_val);
            if (j + j / i <= n) pref[j + j / i] = sub(pref[j + j / i], dp_val);
        }
        cur_sum = sum(cur_sum, dp_val);
    }
    cout << last;

    return 0;
}