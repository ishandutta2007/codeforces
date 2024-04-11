#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int x;
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
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
void solve() {
    int x;
    string s;
    cin >> x >> s;
    string cur = s;
    int len = s.size();
    while (cur.size() > x) cur.pop_back();
    for (int it = 1; it <= x; it++) {
        int add = mult(sub(len, it), cur[it - 1] - '0' - 1);
        int prv_len = len;
        len = sum(len, add);
        for (int j = 0; j < cur[it - 1] - '0' - 1; j++) {
            for (int p = it; p < prv_len; p++) {
                if (cur.size() >= x) break;
                cur += cur[p];
            }
        }
    }
    cout << len << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}