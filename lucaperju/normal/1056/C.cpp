#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int lgput (long long a, long long exp, long long mod)
{
    long long rez=1;
    while(exp)
        if(exp&1)rez*=a,rez%=mod,--exp;
            else a*=a,a%=mod,exp>>=1;
    rez%=mod;
    return rez;
}
int cmmdc (int a, int b)
{
    int r;
    while(b)r=a%b,a=b,b=r;
    return a;
}
long long care[2003];
bool ok[2003];
struct ura
{
    int val,poz;
}v[2003];
bool cmp (ura a, ura b)
{
    if(a.val<b.val)
        return true;
    return false;
}
int main()
{
    long long t,s=0,cr,i,a,b,c,mx1=0,mx2=0,cnt=0,pz1,pz2,kk=0,pas=1<<20,j,x,y,cj1,cj2,n,m,k;
    cin>>n>>m;
    n*=2;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].val;
        v[i].poz=i;
    }
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        care[a]=b;
        care[b]=a;
    }
    cin>>t;
    while(t==2)
    {
        if(cnt<n/2)
            cin>>a;
        else
            return 0;
        ++cnt;
        ok[a]=1;
        t=1;
        if(care[a])
        {
            cout<<care[a]<<'\n';
            ok[care[a]]=1;
            cout.flush();
            t=2;
        }
    }
    sort(v+1,v+n+1,cmp);
    for(i=n;i>=1;--i)
    {
        if(care[v[i].poz] && ok[v[i].poz]!=1)
        {
            cout<<v[i].poz<<'\n';
            cout.flush();
            if(cnt<n/2)
            cin>>b;
            if(b==-1)
                return 0;
            ++cnt;
            ok[v[i].poz]=1;
            ok[b]=1;
        }
    }
    for(i=n;i>=1;--i)
    {
        if(ok[v[i].poz]!=1)
        {
            cout<<v[i].poz<<'\n';
            cout.flush();
            if(cnt<n/2)
            cin>>b;
            if(b==-1)
                return 0;
            ++cnt;
            ok[v[i].poz]=1;
            ok[b]=1;
        }
    }
    return 0;
}