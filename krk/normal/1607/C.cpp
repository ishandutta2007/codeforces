#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ll cur = 0;
        sort(a, a + n);
        ll best = -1000000000;
        for (int i = 0; i < n; i++) {
            best = max(best, a[i] + cur);
            cur -= (a[i] + cur);
        }
        printf("%I64d\n", best);
    }
    return 0;
}