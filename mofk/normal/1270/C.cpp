#include <bits/stdc++.h>

using namespace std;

int n;
long long s, x;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        s = x = 0;
        int v;
        for (int i = 1; i <= n; ++i) cin >> v, s += v, x ^= v;
        long long inf = 1LL << 55;
        if ((s + inf) % 2 == 1) ++inf;
        s += inf, x ^= inf;
        assert(s <= 2 * x);
        long long a = x - s / 2;
        cout << 3 << '\n';
        cout << inf << ' ' << a << ' ' << a << '\n';
    }
    return 0;
}