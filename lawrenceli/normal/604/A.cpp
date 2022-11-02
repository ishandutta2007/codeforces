#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int m[10], w[10], hs, hu;

int main() {
    int ans = 0;
    for (int i = 0; i < 5; i++) cin >> m[i];
    for (int i = 0; i < 5; i++) cin >> w[i];
    cin >> hs >> hu;

    for (int i = 0; i < 5; i++)
        ans += max(150 * (i+1), 2 * (i+1) * (250 - m[i]) - 50 * w[i]);
    cout << ans + 100 * hs - 50 * hu << '\n';
}