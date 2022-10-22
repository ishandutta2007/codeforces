#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int Maxn = 105;
const ll Inf = 1000000000000000000LL;

int n;
ii fig[Maxn];
int t;
ll p[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%I64d %I64d", &fig[i].second, &fig[i].first);
    sort(fig, fig + n);
    scanf("%d", &t);
    for (int i = 0; i < t; i++) scanf("%I64d", &p[i]);
    p[t] = Inf;
    int a = 0, b = 0;
    ll lft = p[0];
    while (a < n) {
        ll take = min(fig[a].second, lft); res += take * fig[a].first * ll(b + 1LL);
        fig[a].second -= take; lft -= take;
        if (fig[a].second == 0) a++;
        if (lft == 0) { b++; lft = p[b] - p[b - 1]; }
    }
    printf("%I64d\n", res);
    return 0;
}