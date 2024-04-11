#include <cstdio>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (a[n - 1] == 1) printf("NO\n");
    else if (n == 1) {
        printf("YES\n");
        printf("%d\n", a[n - 1]);
    } else if (a[n - 2] == 1) {
        printf("YES\n");
        for (int i = 0; i < n; i++)
            printf("%d%s", a[i], i + 1 < n? "->": "\n");
    } else {
        int lst = n - 3;
        while (lst >= 0 && a[lst] == 1) lst--;
        if (lst < 0) printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 0; i < lst; i++)
                printf("%d->", a[i]);
            printf("(0->(");
            for (int i = lst + 1; i < n - 2; i++)
                printf("%d->", a[i]);
            printf("0))->0\n");
        }
    }
    return 0;
}