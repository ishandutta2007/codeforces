#include <iostream>
#include<cstdio>
using namespace std;
int n,m,i,a[200002];
long long ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i-1]>0)
        {
            ans++;
            a[i]+=a[i-1];
            a[i]-=m;
        }
        if(a[i]>=m)
        {
            ans+=a[i]/m;
            a[i]%=m;
        }
    }
    if(a[n]>0) ans++;
    cout<<ans;
    return 0;
}