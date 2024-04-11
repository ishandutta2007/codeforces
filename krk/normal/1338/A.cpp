#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

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
        ll my = 0;
        int lst = a[0];
        for (int i = 1; i < n; i++) {
            int dif = lst - a[i];
            while ((1ll << my) <= dif) my++;
            lst = max(lst, a[i]);
        }
        printf("%I64d\n", my);
    }
    return 0;
}