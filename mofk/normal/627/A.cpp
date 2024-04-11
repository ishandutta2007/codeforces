#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long s, x;
    cin >> s >> x;
    if (s < x) return cout << 0 << endl, 0;
    if (s % 2 != x % 2) return cout << 0 << endl, 0;
    long long h = (s - x) / 2;
    if ((h & x) != 0) return cout << 0 << endl, 0;
    long long ans = (1LL << __builtin_popcountll(x));
    if (s == x) ans -= 2;
    cout << ans << endl;
}