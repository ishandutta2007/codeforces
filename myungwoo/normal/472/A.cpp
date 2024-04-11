#include <stdio.h>

bool V[1000001];

int main()
{
    int n, i, k;
    scanf("%d",&n);
    for (i=2;i<n;i++) if (!V[i]) for (k=i+i;k<n;k+=i) V[k] = 1;
    for (i=2;i<n;i++) if (V[i] && V[n-i]){ printf("%d %d\n",i,n-i); break; }
}