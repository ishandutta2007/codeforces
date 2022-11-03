#include <cstdio>
#include <algorithm>
using namespace std;
int n,k,a[100005];
int main()
{
    int i;
    scanf("%d%d",&n,&k);
    if(n==1) { int t; scanf("%d",&t); printf("%d\n",t); }
    else if(k==1)
    {
        int res=0x7fffffff,t;
        for(i=0;i<n;i++) scanf("%d",&t),res=min(res,t);
        printf("%d\n",res);
    }
    else if(k==2)
    {
        int a,b;
        scanf("%d",&a);
        for(i=2;i<n;i++) scanf("%*d");
        scanf("%d",&b);
        printf("%d\n",max(a,b));
    }
    else
    {
        int res=0x80000000,t;
        for(i=0;i<n;i++) scanf("%d",&t),res=max(res,t);
        printf("%d\n",res);
    }
    return 0;
}