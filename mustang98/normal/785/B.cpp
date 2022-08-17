#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;

int main()
{
    int n, m;
    int maxs = -inf, mins = inf;
    int maxp = -inf, minp = inf;
    int l, r;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l, &r);
        maxs = max(maxs, l);
        mins = min(mins, r);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &l, &r);
        maxp = max(maxp, l);
        minp = min(minp, r);
    }
    int ans = max(0, max(maxp - mins, maxs - minp));
    cout << ans;
    return 0;
}