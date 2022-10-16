#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int a,b,pz;
}v[300005];
bool cmp1 (ura a, ura b)
{
    return a.b>b.b;
}
bool cmp2 (ura a, ura b)
{
    return a.b<b.b;
}
int main ()
{
    long long n,m,ta,tb,k=0,i,j,nrc=0,nrd=0;
    long long mn=0LL;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].a>>v[i].b;
        if(v[i].b>v[i].a)
            ++nrc;
        else
            ++nrd;
        v[i].pz=i;
    }
    cout<<max(nrc,nrd)<<'\n';
    if(nrc>nrd)
    {
        for(i=1;i<=n;++i)
        {
            if(v[i].b<v[i].a)
                v[i].b=v[i].a=-1;
        }
        sort(v+1,v+n+1,cmp1);
        for(i=1;i<=nrc;++i)
            cout<<v[i].pz<<' ';
    }
    else
    {
        for(i=1;i<=n;++i)
        {
            if(v[i].b>v[i].a)
                v[i].b=v[i].a=99999999;
        }
        sort(v+1,v+n+1,cmp2);
        for(i=1;i<=nrd;++i)
            cout<<v[i].pz<<' ';
    }
    return 0;
}