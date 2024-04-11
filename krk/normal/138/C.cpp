#include <cstdio>
#include <algorithm>
#define mp make_pair
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 10005;
const int Maxt = 200005;

int n, m;
int a[Maxn], h[Maxn], l[Maxn], r[Maxn];
ii sorted[Maxm];
int z[Maxm];
int lef[Maxt], rig[Maxt];
double prob[Maxt];
double res;

void Create(int v, int lf, int rg)
{
     lef[v] = lf, rig[v] = rg;
     prob[v] = 1.0;
     if (lf == rg) return;
     int mid = lf + rg >> 1;
     Create(2 * v, lf, mid); Create(2 * v + 1, mid + 1, rg);
}

void Insert(int v, int lf, int rg, double p)
{
     if (lef[v] == lf && rig[v] == rg) prob[v] *= p;
     else {
          int mid = lef[v] + rig[v] >> 1;
          if (lf <= mid) Insert(2 * v, lf, min(mid, rg), p);
          if (mid < rg) Insert(2 * v + 1, max(mid + 1, lf), rg, p);
     }
}

double Get(int v, int x)
{
     if (lef[v] == x && rig[v] == x) return prob[v];
     int mid = lef[v] + rig[v] >> 1;
     if (x <= mid) return prob[v] * Get(2 * v, x);
     return prob[v] * Get(2 * v + 1, x);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d %d %d %d", &a[i], &h[i], &l[i], &r[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &sorted[i].first, &z[i]); sorted[i].second = i;
    }
    sort(sorted, sorted + m);
    Create(1, 0, m - 1);
    for (int i = 0; i < n; i++) {
        int li = upper_bound(sorted, sorted + m, mp(a[i] - h[i], -1)) - sorted;
        int ri = upper_bound(sorted, sorted + m, mp(a[i], -1)) - sorted - 1;
        if (li <= ri) Insert(1, li, ri, double(100 - l[i]) / 100.0);
        li = upper_bound(sorted, sorted + m, mp(a[i] + 1, -1)) - sorted;
        ri = upper_bound(sorted, sorted + m, mp(a[i] + h[i] + 1, -1)) - sorted - 1;
        if (li <= ri) Insert(1, li, ri, double(100 - r[i]) / 100.0);
    }
    for (int i = 0; i < m; i++) res += z[sorted[i].second] * Get(1, i);
    printf("%.9lf\n", res);
    return 0;
}