#include <bits/stdc++.h>

using namespace std;
long long v[5005],d[5005][5005],st[5005];
int main()
{
    long long k,n,i,j,m,mn=9999999,pz,a,b,s,x,y;
    long long mx=0;
    char c;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    i=j=1;
    while(j<=n)
    {
        if(v[j]-v[i]<=5)
        {
            st[j]=i-1;
            ++j;
        }
        else
            ++i;
    }
    for(i=1;i<=n;++i)
    {
        for(j=0;j<=k;++j)
        {
            if(j==0)
                d[i][j]=d[i-1][j];
            else
                d[i][j]=max(d[st[i]][j-1]+i-st[i],d[i-1][j]);
        }
    }
    for(i=0;i<=k;++i)
        mx=max(mx,d[n][i]);
    cout<<mx;
    return 0;
}