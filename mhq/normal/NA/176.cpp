#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll n, p;
bool ok(ll n, int cnt) {
    if (n < cnt) return false;
    int bits = 0;
    for (int i = 0; i <= 60; i++) {
        if (n & (1LL << i)) bits++;
    }
    return bits <= cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> p;
    for (int i = 1; i <= 100; i++) {
        if (ok(n - i * p, i)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}