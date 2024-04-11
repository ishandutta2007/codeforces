#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
struct ura
{
    long long a,b,c;
}v[400005];
long long val[200005],t[200005];
bool cmp (ura a, ura b)
{
    if(a.c<b.c)
        return true;
    return false;
}
int tata (int a)
{
    if(t[a]==0)
        return a;
    else
        t[a]=tata(t[a]);
    return t[a];
}
int main()
{
    long long n,i,j=0,k=0,s=0,okneg=0,cnt=0,mn=99999999999999LL,m,cur,pz,a,b,vl1=1,ok,sus=1,jos=1,cnt1=0;
    cin>>n>>m;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        cin>>val[i];
        if(val[i]<mn)
            mn=val[i],pz=i;
    }
    for(i=1;i<=n;++i)
        if(i!=pz)
            v[++k].a=pz,/**/v[k].b=i,/**/v[k].c=mn+val[i];
    for(i=1;i<=m;++i)
    {
        long long c;
        cin>>a>>b>>c;
        v[++k].a=a;
        v[k].b=b;
        v[k].c=c;
    }
    sort(v+1,v+k+1,cmp);
    for(i=1;i<=k;++i)
    {
        if(tata(v[i].a)!=tata(v[i].b))
        {
            s+=v[i].c;
            t[tata(v[i].a)]=tata(v[i].b);
        }
    }
    cout<<s;
}