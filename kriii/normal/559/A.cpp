#include <stdio.h>

int sq(int a)
{
        return a *a;
}

int main()
{
    int a[6];
    for (int i=0;i<6;i++) scanf("%d",&a[i]);
    int u = sq(a[0]+a[1]+a[2]) - sq(a[0])- sq(a[2]) - sq(a[4]);
    printf ("%d\n",u);

    return 0;
}