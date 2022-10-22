#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, h;
ii a[Maxn];
int res[Maxn];
int best, bi;

int Max(int lim)
{
    int res = a[lim].first + a[n - 1].first + h;
    if (lim < n - 2) res = max(res, a[n - 2].first + a[n - 1].first);
    return res;
}

int Min(int lim)
{
    int res;
    if (lim == 0) {
        res = a[0].first + a[1].first + h;
        if (n >= 3) res = min(res, a[1].first + a[2].first);
    } else res = a[0].first + a[1].first;
    return res;
}

int main()
{
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first); a[i].second = i;
    }
    sort(a, a + n);
    best = a[n - 1].first + a[n - 2].first - a[0].first - a[1].first; bi = n - 1;
    for (int i = 0; i + 1 < n; i++) {
        int cand = Max(i) - Min(i);
        if (cand < best) { best = cand; bi = i; }
    }
    for (int i = bi + 1; i < n; i++)
        res[a[i].second] = 1;
    printf("%d\n", best);
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i] + 1, i + 1 < n? ' ': '\n');
    return 0;
}