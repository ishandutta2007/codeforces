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
char a[100005],b[100005];
int main()
{
   // ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=1,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci,m;
    char cc;
    cin>>n>>ws>>a>>b;
    long long c1=0,c0=0,c10=0,c01=0;
    for(i=0;i<n;++i)
    {
        if(a[i]=='1')
            ++c1;
        if(a[i]=='0' && b[i]=='0')
            ++c0;
        if(a[i]=='1' && b[i]=='0')
            ++c10;
        if(a[i]=='0' && b[i]=='1')
            ++c01;
    }
    cout<<c1*1LL*c0+c10*1LL*c01;
    return 0;
}