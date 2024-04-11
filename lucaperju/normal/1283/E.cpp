#include <bits/stdc++.h>
using namespace std;
int v[200005];
int fv[200005];
int main()
{
    int n,t,i,j,k=0,pas=1<<20,m,mx=0,sc,rz;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        ++v[a];
    }
    for(i=1;i<=n;++i)
    {
        int cur=v[i];
        cur+=fv[i-1]+fv[i];
        for(j=i-1;j<=i+1;++j)
            if(cur)
                fv[j]=1,--cur;
    }
    for(i=0;i<=n+1;++i)
    {
        mx+=fv[i];
        fv[i]=0;
    }
    for(i=1;i<=n;++i)
    {
        if(v[i]==0)
            continue;
        for(j=i-1;j<=i+1;++j)
            if(fv[j])
                break;
        if(fv[j])
            continue;
        fv[i+1]=1;
    }
    for(i=0;i<=n+1;++i)
        k+=fv[i];
    cout<<k<<' '<<mx;
    return 0;
}