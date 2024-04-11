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

long long a[200005],b[200005];
int main()
{
   // ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=1,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci,m,rez=1;
    char cc;
    long long c,d,pas,ck;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i];
    }
    i=j=1;
    cur=0;
    while(j<=n && i<=n)
    {
        while(cur<m && j<=n)
        {
            ++j;
            cur+=a[j]-b[j-1];
        }
        cur-=a[j]-b[j-1];
        --j;
        if(b[j]-a[i]+m-cur>mx1)
        {
            mx1=b[j]-a[i]+m-cur;
        }
        ++j;
        cur+=a[j]-b[j-1];
        ++i;
        cur-=a[i]-b[i-1];
    }
    cout<<mx1;
    return 0;
}