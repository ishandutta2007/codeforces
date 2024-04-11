

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

long long a[100005],b[100005],ra[200005];
int main()
{
   // ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=0,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci,m;
    char cc;
    long long c,d,pas,ck;
    cin>>n>>l;
    for(i=1;i<=n;++i)
        cin>>a[i];
    cin>>m>>l;
    for(i=1;i<=m;++i)
        cin>>b[i];
    pas=1;
    while(pas<=1000000000LL)
    {
        pas<<=1LL;
        for(i=1;i<=n;++i)
            ra[i]=a[i]%pas;
        for(i=n+1;i<=n+m;++i)
            ra[i]=(b[i-n]+pas/2LL)%pas;
        sort(ra+1,ra+n+m+1);
        for(i=1;i<=n+m;++i)
        {
            if(i==1 || ra[i]!=ra[i-1])
                s=1;
            else
                ++s;
            if(s>mx1)
                mx1=s;
        }
    }
    if(n==1 && m==1 && a[1]==b[1])
        cout<<2;
    else
    cout<<mx1;
    return 0;
}