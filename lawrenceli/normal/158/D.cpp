#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

const int MAXN = 20100;

int n, k, t[MAXN], ans = -1e9, grp[MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> t[i];

    for (k=1; k<=n; k++) {
        if (n % k) continue;
        if (n / k <= 2) continue;
        memset(grp, 0, sizeof(grp));
        for (int i=0; i<n; i++)
            grp[i % k] += t[i];

        for (int i=0; i<k; i++)
            ans = max(ans, grp[i]);
    }

    cout << ans << '\n';
    return 0;
}