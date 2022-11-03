#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,a[maxn],pre[maxn];
int main()
{
    int i;
    long long s1=0,s2=0;
    scanf("%d",&n);
    for(a[0]=1,i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>0) a[i]=1;
        if(a[i]<0) a[i]=-1;
        a[i]*=a[i-1];
    }
    pre[0]=1;
    for(i=1;i<=n;i++)
        pre[i]=pre[i-1]+(a[i]==1);
    for(i=1;i<=n;i++)
        if(a[i]==1)
            s1+=pre[i-1],s2+=i-pre[i-1];
        else s2+=pre[i-1],s1+=i-pre[i-1];
    printf("%lld %lld\n",s2,s1);
    return 0;
}