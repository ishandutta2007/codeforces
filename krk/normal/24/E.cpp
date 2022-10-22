#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 500005;
const ld eps = 1e-11L;
const ld Inf = 1e20;

int n;
pair <ld, ld> c[Maxn];
ld res = -1.0L;

bool Enough(ld t) 
{
     ld r = -Inf;
     for (int i = 0; i < n; i++)
         if (c[i].second > 0) r = max(r, c[i].first + t * c[i].second);
         else if (c[i].first + t * c[i].second <= r + eps) return true;
     return false;
}

void Search()
{
     ld l = 0.0, r = 2000000000.0;
     int cnt = 68;
     while (cnt--) {
           ld mid = (l + r) / 2.0L;
           if (Enough(mid)) {
                            res = mid;
                            r = mid;
           } else l = mid;
     }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, v; scanf("%d %d", &x, &v);
        c[i].first = x; c[i].second = v;
    }
    sort(c, c + n);
    Search();
    if (res < 0.0L) printf("-1\n");
    else printf("%.11lf\n", double(res));
    return 0;
}