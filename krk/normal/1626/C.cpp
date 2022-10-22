#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 105;

int T;
int n;
ii p[Maxn];

ll Sum(ll lef, ll rig)
{
    return (lef + rig) * (rig - lef + 1) / 2;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &p[i].first);
        for (int i = 0; i < n; i++)
            scanf("%d", &p[i].second);
        for (int i = n - 2; i >= 0; i--)
            p[i].second = max(p[i].second, p[i + 1].second - (p[i + 1].first - p[i].first));
        int cur = 0, lst = 0;
        ll res = 0;
        for (int i = 0; i < n; i++)
            if (p[i].first - lst >= p[i].second) {
                res += Sum(1, p[i].second);
                cur = p[i].second;
                lst = p[i].first;
            } else {
                res += Sum(cur + 1, cur + (p[i].first - lst));
                cur += p[i].first - lst;
                lst = p[i].first;
            }
        printf("%I64d\n", res);
    }
    return 0;
}