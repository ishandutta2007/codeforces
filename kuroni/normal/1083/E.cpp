#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define fi first
#define se second
using namespace std;

const int N = 1E6 + 5;

int n;
long long ans = 0;

struct SQuery
{
    int x, y;
    long long v;
} a[N];

struct SLine
{
    int a;
    long long b;
};
vector<SLine> ve;
vector<double> po;

double inter(const SLine &x, const SLine &y)
{
    return -1.0 * (x.b - y.b) / (x.a - y.a); 
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%lld", &a[i].x, &a[i].y, &a[i].v);
        a[i].v = 1LL * a[i].x * a[i].y - a[i].v;
    }
    sort(a + 1, a + n + 1, [](const SQuery &a, const SQuery &b) { return a.x < b.x; });
    ve.push_back((SLine){0, 0});
    for (int i = 1; i <= n; i++)
    {
        int pos = distance(po.begin(), upper_bound(po.begin(), po.end(), a[i].y, greater<double>()));
        ans = max(ans, a[i].v += 1LL * a[i].y * ve[pos].a + ve[pos].b);
        SLine cur = (SLine){-a[i].x, a[i].v};
        while (ve.size() >= 2 && inter(cur, ve[ve.size() - 2]) >= po.back())
        {
            po.pop_back();
            ve.pop_back();
        }
        po.push_back(inter(ve.back(), cur));
        ve.push_back(cur);
    }
    printf("%lld", ans);
}