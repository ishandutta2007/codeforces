#include<bits/stdc++.h>
using namespace std;
long long n,m,i,f,mini,g,s;
int main(){
    cin>>n>>m;
    long long a[n+1],b[m+1],c[m+1],d[n+3];
    a[0]=0;
    a[n+1]=1e9;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n+3;i++)
    {
        d[i]=0;
    }
    for(i=1;i<=m;i++)
    {
        //cin>>b[i]>>c[i]>>f;
        scanf("%lld %lld %lld",&b[i],&c[i],&f);
        if(b[i] != 1)
        {
            c[i]=0;
        }
    }
    sort(c+1,c+m+1);
    s=1;
    if(n>=2)
    {
        for(i=1;i<=m;i++)
        {
            if(s!=n+1)
            {
                if(a[s]<=c[i] && a[s+1]>c[i] && c[i]>=a[1])
                {
                    d[s]++;
                }
                else if(c[i]>=a[1])
                {
                    s++;
                    i--;
                }
            }
            else
            {
                if(c[i]==1e9)
                {
                    d[s]++;
                }
            }
        }
    }
    else if(n==1)
    {
        for(i=1;i<=m;i++)
        {
            if(c[i]>a[1] && c[i]!=1e9)
            {
                d[1]++;
            }
            else if(c[i]==1e9)
            {
                d[2]++;
            }
        }
    }
    else if(n==0)
    {
        for(i=1;i<=m;i++)
        {
            if(c[i]==1e9)
            {
                d[1]++;
            }
        }
    }
    for(i=n;i>=1;i--)
    {
        d[i]+=d[i+1];
    }
    mini=1000000000;
    for(i=1;i<=n+1;i++)
    {
        if(mini>=d[i]+i-1)
        {
            mini=d[i]+i-1;
        }
    }
    cout<<mini;
    return 0;
}