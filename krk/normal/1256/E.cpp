#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
ii a[Maxn];
ii best[3];
int par[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    best[0] = best[1] = best[2] = ii(0, 0);
    for (int i = 3; i < n; i++) {
        par[i] = best[0].second;
        ii add = ii(best[0].first + (a[i].first - a[i - 1].first), i);
        best[0] = max(best[0], best[1]);
        best[1] = best[2];
        best[2] = add;
    }
    par[n] = best[0].second;
    printf("%d ", a[n - 1].first - a[0].first - best[0].first);
    int cnt = 0;
    int v = n;
    while (v > 0) {
        int u = par[v];
        cnt++;
        for (int i = u; i < v; i++)
            res[a[i].second] = cnt;
        v = u;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}