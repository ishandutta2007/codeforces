#include <bits/stdc++.h>

using namespace std;
struct ura
{
    long long cat,cst,pz;
}v[100005];
long long poz[100005];
bool cmp (ura a, ura b)
{
    if(a.cst<b.cst)
        return true;
    if(a.cst>b.cst)
        return false;
    if(a.pz<b.pz)
        return true;
    return false;
}
int main()
{
    long long n,i,j=1,k,s=0,cur,pz,m,ok=0;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].cat;
        s+=v[i].cat;
        v[i].pz=i;
    }
    for(i=1;i<=n;++i)
        cin>>v[i].cst;
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;++i)
    {
        poz[v[i].pz]=i;
    }
    for(i=1;i<=m;++i)
    {
        long long a,b;
        cin>>a>>b;
        if(b>s)
        {
            ok=1;
        }
        if(ok==1)
        {
            cout<<0<<'\n';
            continue;
        }
        long long cnt=0;
        if(b<=v[poz[a]].cat)
        {
            v[poz[a]].cat-=b;
            s-=b;
            cnt+=v[poz[a]].cst*1LL*b;
        }
        else
        {
            cnt+=v[poz[a]].cst*1LL*v[poz[a]].cat;
            b-=v[poz[a]].cat;
            s-=v[poz[a]].cat;
            v[poz[a]].cat=0;
            while(b)
            {
                cnt+=min(b,v[j].cat)*1LL*v[j].cst;
                long long x=min(b,v[j].cat);
                b-=x;
                v[j].cat-=x;
                s-=x;
                if(b>0)
                    ++j;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}