#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}
#define answer(ans) {cout << (ans) << '\n'; return;}

void solve() {
    ll n;
    cin >> n;
    if (n % 2 == 1) answer(2)
    ll d = n;
    while (d % 2 == 0) d /= 2;
    if ((d + 1) / 2 > n / d) {
        ll e = 2 * n / d;
        if ((e + 1) / 2 > n / e) answer(-1)
        answer(e)
    }
    if (d == 1) answer(-1)
    answer(d)
}