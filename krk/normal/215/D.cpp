#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

ll n, m;
ll t[Maxn], T[Maxn], x[Maxn], cost[Maxn];
ll res;

ll DivUp(ll a, ll b)
{
    return a / b + (a % b > 0LL);
}

int main()
{
    scanf("%I64d %I64d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%I64d %I64d %I64d %I64d", &t[i], &T[i], &x[i], &cost[i]);
    for (int i = 0; i < n; i++)
        if (t[i] + m <= T[i]) res += cost[i];
        else {
            ll mn = m * x[i] + cost[i];
            if (t[i] < T[i]) {
                mn = min(mn, DivUp(m, T[i] - t[i]) * cost[i]);
                ll v = m % (T[i] - t[i]);
                mn = min(mn, v * x[i] + cost[i] + DivUp(m - v, T[i] - t[i]) * cost[i]);
            }
            res += mn;
        }
    printf("%I64d\n", res);
    return 0;
}