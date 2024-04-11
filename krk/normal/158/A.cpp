#include <cstdio>
using namespace std;

const int Maxn = 55;

int n, k;
int a[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int i = 0;
    while (i < n && a[i] && a[i] >= a[k - 1]) i++;
    printf("%d\n", i);
    return 0;
}