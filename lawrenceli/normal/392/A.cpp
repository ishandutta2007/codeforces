#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int n; cin >> n;
    if (n == 0) {
        cout << 1;
        return 0;
    }

    ll ans = 0;
    int prev = n;
    for (int i=1; i<=n; i++) {
        int x = int(sqrt(ll(n) * n - ll(i) * i));
        ans += max(1, prev - x);
        prev = x;
    }

    cout << ans*4 << '\n';
    return 0;
}