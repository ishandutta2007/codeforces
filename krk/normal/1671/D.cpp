#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Inf = 1000000000;
const ll bInf = 1000000000000000000ll;

int T;
int n, x;
int a[Maxn];
ii best[2];

void addBest(const ii &p)
{
    if (p < best[0]) best[1] = best[0], best[0] = p;
    else if (p < best[1]) best[1] = p;
}

int getBest(int ind)
{
    if (best[0].second == ind) return best[1].first;
    return best[0].first;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        ll sum = 0;
        for (int i = 1; i < n; i++)
            sum += abs(a[i] - a[i + 1]);
        best[0] = best[1] = ii(Inf, -1);
        for (int i = 0; i <= n; i++) {
            int delt = 0;
            if (i >= 1 && i < n) delt -= abs(a[i] - a[i + 1]);
            if (i >= 1) delt += abs(a[i] - 1);
            if (i < n) delt += abs(a[i + 1] - 1);
            addBest(ii(delt, i));
        }
        ll res = bInf;
        for (int i = 0; i <= n; i++) {
            int delt = 0;
            if (i >= 1 && i < n) delt -= abs(a[i] - a[i + 1]);
            if (i >= 1) delt += abs(a[i] - x);
            if (i < n) delt += abs(a[i + 1] - x);
            res = min(res, sum + delt + getBest(i));
        }
        for (int i = 0; i <= n; i++) {
            int delta = x - 1, deltb = x - 1;
            if (i >= 1 && i < n) {
                delta -= abs(a[i] - a[i + 1]);
                deltb -= abs(a[i] - a[i + 1]);
            } 
            if (i >= 1) {
                delta += abs(a[i] - 1);
                deltb += abs(a[i] - x);
            }
            if (i < n) {
                delta += abs(a[i + 1] - x);
                deltb += abs(a[i + 1] - 1);
            }
            res = min(res, sum + min(delta, deltb));
        }
        printf("%I64d\n", res);
    }
    return 0;
}