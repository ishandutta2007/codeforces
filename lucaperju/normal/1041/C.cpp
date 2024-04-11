#include <bits/stdc++.h>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b){r=a%b;a=b;b=r;}
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    else if(cnt<0)
        return 0;
    while(cnt>1){
        if(!(cnt&1)){p=p*1LL*p%mod;cnt>>=1LL;}
        else{--cnt;r=r*1LL*p%mod;}}
    p=p*1LL*r;
    return p%mod;
}
/*struct ura
{
    int val,id;
}a[1005];
bool cmp (ura a, ura b)
{
    if(a.val>b.val)
        return true;
    return false;
}*/

struct ura
{
    long long poz,val,zi;
} v[200005];
bool cmp1 (ura a, ura b)
{
    if(a.val<b.val)
        return true;
    return false;
}
bool cmp2 (ura a, ura b)
{
    if(a.poz<b.poz)
        return true;
    return false;
}
int main()
{
   // ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=1,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci,m,rez=1;
    char cc;
    long long a,b,c,d,pas,ck;
    cin>>n>>m>>d;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].val;
        v[i].poz=i;
    }
    sort(v+1,v+n+1,cmp1);
    i=j=1;
    while(j<=n && i<=n)
    {
        while(v[j].val-v[i].val<=d && j<=n)
            ++j;
        if(j-i>mx1)
            mx1=j-i;
        ++i;
    }
    cout<<mx1<<'\n';
    for(i=1;i<=n;++i)
        v[i].zi=(i-1)%mx1+1;
    sort(v+1,v+n+1,cmp2);
    for(i=1;i<=n;++i)
        cout<<v[i].zi<<' ';
    return 0;
}