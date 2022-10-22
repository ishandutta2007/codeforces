#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;

int T;
int n;
int a[Maxn];
ll mn[2];
ll sum;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        sum = 0;
        ll delt = 0;
        mn[0] = 0;
        mn[1] = Inf;
        ll st = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (i % 2) {
                sum += a[i];
                st -= a[i];
            } else st += a[i];
            delt = max(delt, st - mn[i % 2]);
            mn[i % 2] = min(mn[i % 2], st);
        }
        printf("%I64d\n", sum + delt);
    }
    return 0;
}