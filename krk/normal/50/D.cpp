#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long double ld;

const int Maxn = 105;
const ld eps = 1e-9L;

int n, k, e;
int x[Maxn], y[Maxn];
ld res;

ld Dist(ld x1, ld y1, ld x2, ld y2)
{
     return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ld P(ld D, ld R)
{
     if (D <= R) return 1.0L;
     return exp(1.0L - (D / R) * (D / R));
}

bool Enough(ld r)
{
     ld prob[Maxn] = {1.0L};
     for (int i = 1; i <= n; i++)
         for (int j = i - 1; j >= 0; j--) {
             ld p = P(Dist(x[i], y[i], x[0], y[0]), r);
             prob[j + 1] += p * prob[j];
             prob[j] *= 1.0L - p;
         }
     ld fail = 0.0L;
     for (int i = 0; i < k; i++) fail += prob[i];
     return 1000.0L * fail + eps <= e;
}

void Search(ld l, ld r)
{
     if (l + eps > r) return;
     ld mid = (l + r) / 2;
     if (Enough(mid)) {
                      res = mid;
                      Search(l, mid - eps);
     } else Search(mid + eps, r);
}

int main()
{
    cin >> n >> k >> e;
    for (int i = 0; i <= n; i++) cin >> x[i] >> y[i];
    Search(eps, 3000.0L);
    cout << fixed << setprecision(12) << res << endl;
    return 0;
}