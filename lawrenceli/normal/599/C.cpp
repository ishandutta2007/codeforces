#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100100;

int n, h[maxn], suf[maxn];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    suf[n] = 1e9;
    for (int i = n-1; i >= 0; i--)
        suf[i] = min(suf[i+1], h[i]);

    int ma = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ma = max(ma, h[i]);
        if (ma <= suf[i+1]) ans++;
    }

    cout << ans << '\n';
}