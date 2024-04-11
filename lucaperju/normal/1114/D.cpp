#include <bits/stdc++.h>

using namespace std;
int vv[5005],v[5005],d[5005][5005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long i,j=0,n,mn=(1LL<<63)-1+(1LL<<63),k=0,pz=-1,sc=0,x,y,z,a,b,c,m;
    int mx=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>vv[i];
    for(i=1;i<=n;++i)
    {
        if(vv[i]!=vv[i-1])
            v[++j]=vv[i];
    }
    n=j;
    for(i=1;i<n;++i)
        for(j=n;j>i;--j)
        {
            if(v[i]==v[j])
                d[i][j]=1+d[i-1][j+1];
            else
                d[i][j]=max(d[i-1][j],d[i][j+1]);
        }
    for(i=2;i<n;++i)
        mx=max(mx,d[i-1][i+1]);
    cout<<n-mx-1;
}