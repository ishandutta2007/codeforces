#include <cstdio>
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 100005;

int n, p;
int l[Maxn], r[Maxn];
ld res;

int Has(int l, int r)
{
    return r / p - (l - 1) / p;
}

int main()
{
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &l[i], &r[i]);
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        ll ok = ll(Has(l[i], r[i])) * (r[ni] - l[ni] + 1) +
                ll(Has(l[ni], r[ni])) * (r[i] - l[i] + 1) -
                ll(Has(l[i], r[i])) * Has(l[ni], r[ni]);
        ll all = ll(r[i] - l[i] + 1) * (r[ni] - l[ni] + 1);
        res += ld(ok) / all;
    }
    printf("%.10lf\n", double(2000.0l * res));
    return 0;
}