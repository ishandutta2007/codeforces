#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
ll delt[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            delt[i] = 0;
        }
        ll res = 0;
        for (int i = 1; i + 1 <= n; i++)
            if (a[i] > a[i + 1]) {
                ll val = a[i] - a[i + 1];
                delt[1] -= val; delt[i + 1] += val;
                res += val;
            } else {
                ll val = a[i + 1] - a[i];
                delt[i + 1] -= val; delt[n + 1] += val;
                res += val;
            }
        ll my = a[1] + delt[1];
        res += abs(my);
        printf("%I64d\n", res);
    }
    return 0;
}