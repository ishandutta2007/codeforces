#include <bits/stdc++.h>

using namespace std;
long long v[200005];
struct ura
{
    long long val,pz,ok;
}vs[200005];
int ok[200005];
bool cmp (ura a, ura b)
{
    return a.val<b.val;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long i,j=0,n,mn=9999999999LL,k=0,pz=-1,sc=0,x,y,z,a,b,c,m,cat;
    long long mx=-mn;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        vs[i].val=v[i];
        vs[i].pz=i;
        vs[i].ok=0;
    }
    sort(vs+1,vs+n+1,cmp);
    cat=m*k;
    for(i=n;i>=1 && cat;--i,--cat)
    {
        sc+=vs[i].val;
        ok[vs[i].pz]=-1;
    }
    cout<<sc<<'\n';
    sc=0;
    --k;
    for(i=1;i<=n;++i)
    {
        if(ok[i]==-1)
            ++sc;
        if(sc==m && k)
        {
            cout<<i<<' ';
            sc=0;
            --k;
        }
    }
}