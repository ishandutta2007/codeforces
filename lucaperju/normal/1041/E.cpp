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

long long a[1003],b[1003],fv[1003],rez[1003];
int main()
{
   // ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=0,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci,m;
    char cc;
    long long c,d,pas,ck;
    cin>>n;
    for(i=1;i<n;++i)
    {
        cin>>a[i]>>b[i];
        if(b[i]!=n)
        {
            cout<<"NO";
            return 0;
        }
        ++fv[a[i]];
    }
    cur=1;
    for(i=1;i<=n;++i)
    {
        if(!fv[i])
        {
            ++cur;
            continue;
        }
        if(fv[i]>cur)
        {
            cout<<"NO";
            return 0;
        }
        cur-=fv[i];
        rez[++j]=i;
        cnt=fv[i]-1;
        for(y=1;cnt;++y)
        {
            if(fv[y]==0)
            {
                rez[++j]=y;
                fv[y]=-1;
                --cnt;
            }
        }
        ++cur;
    }
    cout<<"YES\n";
    rez[n]=n;
    for(i=2;i<=n;++i)
    {
        cout<<rez[i-1]<<' '<<rez[i]<<'\n';
    }
    return 0;
}