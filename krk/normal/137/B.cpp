#include <cstdio>
using namespace std;

const int Maxn = 5005;

int n, a;
bool was[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if (a > n) res++;
        else if (was[a]) res++;
             else was[a] = true;
    }
    printf("%d\n", res);
    return 0;
}