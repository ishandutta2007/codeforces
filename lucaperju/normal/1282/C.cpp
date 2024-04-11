#include <iostream>
#include <algorithm>
using namespace std;
struct ura
{
    long long fel,val;
}v[200005];
bool cmp (ura a, ura b)
{
    return a.val<b.val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,m,p,k,i,j,ok=0,t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>n>>m>>a>>b;
        long long cata=0,catb=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i].fel;
            cata+=(v[i].fel==0);
            catb+=(v[i].fel==1);
        }
        for(i=1;i<=n;++i)
            cin>>v[i].val;
        sort(v+1,v+n+1,cmp);
        long long mx=0,sc=0;
        for(i=1;i<=n;++i)
        {
            long long cat=v[i].val-1;
            cat-=sc;
            long long cur=i-1;
            if(cat>=0)
            if(cata*1LL*a<=cat)
                cat-=cata*1LL*a,cur+=cata;
            else
                cur+=cat/a,cat%=a;
            if(cat>=0)
            if(catb*1LL*b<=cat)
                cat-=catb*1LL*b,cur+=catb;
            else
                cur+=cat/b,cat%=b;
            if(cat>=0)
            mx=max(mx,cur);
            cata-=(v[i].fel==0);
            catb-=(v[i].fel==1);
            if(v[i].fel==0)
                sc+=a;
            else
                sc+=b;
        }
        long long cat=m;
            cat-=sc;
            long long cur=i-1;
            if(cat>=0)
            if(cata*1LL*a<=cat)
                cat-=cata*1LL*a,cur+=cata;
            else
                cur+=cat/a,cat%=a;
            if(cat>=0)
            if(catb*1LL*b<=cat)
                cat-=catb*1LL*b,cur+=catb;
            else
                cur+=cat/b,cat%=b;
        if(cat>=0)
        mx=max(mx,cur);
        cout<<mx<<'\n';
    }
}