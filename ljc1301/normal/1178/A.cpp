#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,a[maxn],s,t,c[maxn],m;
int main()
{
    int i;
    scanf("%d",&n);
    s=0;
    for(i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
    m=1,t=a[1],c[0]=1;
    for(i=2;i<=n;i++)
        if(a[i]*2<=a[1])
            t+=a[i],c[m++]=i;
    if(t*2>s)
    {
        printf("%d\n",m);
        for(i=0;i<m;i++) printf("%d ",c[i]);
        printf("\n");
    }
    else printf("0\n");
    return 0;
}