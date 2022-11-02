#include <bits/stdc++.h>

using namespace std;

const int maxn = 10100;

int n;
int deg[maxn];

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++, deg[b]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans += deg[i] * (deg[i] - 1) / 2;
    cout << ans << '\n';
}