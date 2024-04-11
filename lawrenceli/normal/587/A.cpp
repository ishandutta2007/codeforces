#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1000100;

int n, w[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        w[x] ++;
    }

    for (int i = 0; i + 1 < maxn; ++i) {
        w[i+1] += w[i] / 2;
        w[i] %= 2;
    }

    int ans = 0;
    for (int i = 0; i < maxn; ++i) ans += w[i];
    cout << ans << '\n';
}