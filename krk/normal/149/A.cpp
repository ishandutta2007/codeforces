#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 12;

int k, a[Maxn];
int cur;

int main()
{
    scanf("%d", &k);
    for (int i = 0; i < Maxn; i++) scanf("%d", &a[i]);
    sort(a, a + Maxn);
    int i;
    for (i = Maxn - 1; i >= 0 && cur < k; i--) cur += a[i];
    if (cur < k) printf("-1\n");
    else printf("%d\n", Maxn - 1 - i);
    return 0;
}