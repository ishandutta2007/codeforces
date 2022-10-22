#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m;
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    int best[2] = {-1, -1};
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        res += ll(a) * m;
        if (a > best[0]) best[1] = best[0], best[0] = a;
        else if (a > best[1]) best[1] = a;
    }
    int spec = 0;
    for (int i = 0; i < m; i++) {
        int b; scanf("%d", &b);
        if (b < best[0]) { printf("-1\n"); return 0; }
        else if (b > best[0]) { res += b - best[0]; spec++; }
    }
    if (spec == m)
        if (best[1] == -1) { printf("-1\n"); return 0; }
        else res += best[0] - best[1];
    cout << res << endl;
    return 0;
}