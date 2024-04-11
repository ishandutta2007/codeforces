#include <bits/stdc++.h>

using namespace std;
struct ura
{
    int a,b;
}v[105];
int d[10005][105];
bool cmp (ura a, ura b)
{
    return a.b<b.b;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long i,j=0,n,mn=9999999999LL,k=0,pz=-1,s1=0,s2=0,sc=0;
    cin>>n;
    if(n==1)
    {
        cout<<1<<' '<<0;
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        cin>>v[i].a;
        s1+=v[i].a;
    }
    for(i=1;i<=n;++i)
    {
        cin>>v[i].b;
        s2+=v[i].b;
    }
    sort(v+1,v+n+1,cmp);
    for(i=n;i>=1;--i)
    {
        sc+=v[i].b;
        ++k;
        if(sc>=s1)
            break;
    }
    cout<<k<<' ';
    k=n-k;
    for(pz=1;pz<=n;++pz)
    {
        for(j=k-1;j>=1;--j)
        {
            for(i=1;i<=s2-s1-v[pz].b;++i)
            {
                if(d[i][j])
                {
                    if(d[i+v[pz].b][j+1])
                        d[i+v[pz].b][j+1]=min(d[i+v[pz].b][j+1],d[i][j]+v[pz].a);
                    else
                        d[i+v[pz].b][j+1]=d[i][j]+v[pz].a;
                }
            }
        }
        if(d[v[pz].b][1])
            d[v[pz].b][1]=min(d[v[pz].b][1],v[pz].a);
        else
            d[v[pz].b][1]=v[pz].a;
    }
    for(i=1;i<=s2-s1;++i)
    {
        if(d[i][k])
            if(d[i][k]<mn)
                mn=d[i][k];
    }
    if(mn==9999999999LL)
        cout<<0;
    else
        cout<<mn;
}