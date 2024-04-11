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
char rez1[1005],rez2[1005];
int main()
{
   // ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=1,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci;
    char cc;
    cin>>n;
    i=j=n;
    while(i!=1 && j!=1)
    {
     //   if(ok==1)
            cout<<"? "<<ok<<' '<<ok<<' '<<i-1<<' '<<j<<'\n';
     //   else
     //       cout<<"? "<<i-1<<' '<<j<<' '<<ok<<' '<<ok<<'\n';
        cout.flush();
        cin>>cc;
        if(cc=='Y')
        {
            cin>>cc>>cc;
            rez1[++l]='D';
            --i;
        }
        else
        {
            cin>>cc;
            rez1[++l]='R';
            --j;
        }
        if(i+j==n+1)
            break;
    }
    i=j=1;
    while(1)
    {
        cout<<"? "<<i<<' '<<j+1<<' '<<n<<' '<<n<<'\n';
        cout.flush();
        cin>>cc;
        if(cc=='Y')
        {
            cin>>cc>>cc;
            rez2[++r]='R';
            ++j;
        }
        else
        {
            cin>>cc;
            rez2[++r]='D';
            ++i;
        }
        if(i+j==n+1)
            break;
    }
  /*  while(i==1 && j>1)
    {
        rez[++l]='R';
        --j;
    }
    while(j==1 && i>1)
    {
        rez[++l]='D';
        --i;
    }*/
    cout<<"! ";
    for(i=1;i<=r;++i)
        cout<<rez2[i];
    for(;l>=1;--l)
        cout<<rez1[l];
    return 0;
}