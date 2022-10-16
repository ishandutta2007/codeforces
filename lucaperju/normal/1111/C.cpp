#include <bits/stdc++.h>

using namespace std;
long long v[100005],k,a,b;
int cautbin (int pz)
{
    int cr=0,pas=1<<20;
    while(pas)
    {
        if(cr+pas<=k && v[cr+pas]<pz)
            cr+=pas;
        pas>>=1;
    }
    return cr;
}
long long bck (long long st, long long dr)
{
    long long i,j,x,y,c,l,cur2;
    x=cautbin(st);
    y=cautbin(dr+1);
    l=dr-st+1;
    c=y-x;
    if(st==dr)
    {
        if(c!=0)
        return b*1LL*c;
        if(c==0)
            return a;
    }
    if(c==0)
        return a;
    long long mid=(st+dr)/2;
    long long cur=bck(st,mid)+bck(mid+1,dr);
    if(c!=0)
        cur2=l*1LL*c*1LL*b;
    else
        cur2=a;
    return min(cur,cur2);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long i,j,s=0,pz,m,ok=0,n;
    cin>>n>>k>>a>>b;
    for(i=1;i<=k;++i)
        cin>>v[i];
    sort(v+1,v+k+1);
    cout<<bck(1,1LL<<n);
    return 0;
}