#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int i = 0;
    for (int j = 0; j < n; j++) if (a[j] <= a[i]) i = j;
    while (i + 1 < n) { swap(a[i], a[i + 1]); i++; res++; }
    i = n - 1;
    for (int j = n - 1; j >= 0; j--) if (a[j] >= a[i]) i = j;
    while (i > 0) { swap(a[i], a[i + 1]); i--; res++; }
    printf("%d\n", res);
    return 0;
}