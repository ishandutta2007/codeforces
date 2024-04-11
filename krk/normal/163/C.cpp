#include <cstdio>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
using namespace std;

typedef pair <double, int> di;

const int Maxn = 200005;

int n, l, v1, v2;
double d;
vector <di> V;
double res[Maxn];

int main()
{
    scanf("%d %d %d %d", &n, &l, &v1, &v2);
    d = (double) l * v2 / (v1 + v2);
    for (int i = 0; i < n; i++) {
        double a; scanf("%lf", &a);
        double prv = a - d;
        if (prv + 1e-9 < 0.0) {
            V.pb(mp(prv + 2.0 * l, +1)); V.pb(mp(2.0 * l, -1));
            prv = 0.0;
        }
        V.pb(mp(prv, +1)); V.pb(mp(a, -1));
    }
    V.pb(mp(0.0, 0)); V.pb(mp(2.0 * l, 0));
    sort(V.begin(), V.end());
    int cur = 0;
    for (int i = 0; i + 1 < V.size(); i++) {
        cur += V[i].second;
        res[cur] += V[i + 1].first - V[i].first;
    }
    for (int i = 0; i <= n; i++) printf("%.20lf\n", res[i] / (2.0 * l));
    return 0;
}