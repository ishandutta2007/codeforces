#include <iostream>
#include <cstring>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    else
    if(cnt<0)
        return 0;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1LL;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
char v[50][50];
int main()
{
    char c;
    long long a,b,nrca,nrcb,n,i,j,ca,cb,mx=9999999999,mn=9999999999,s=0,k,x,y,z,nra,nrb,ok=0,poz,cur=0,m,cn;
    for(i=1;i<=9;++i)
        for(j=1;j<=9;++j)
            cin>>v[i][j];
    cin>>a>>b;
    a=(a-1)%3+1;
    b=(b-1)%3+1;
    a=(a-1)*3+1;
    b=(b-1)*3+1;
    for(i=a;i<=a+2;++i)
    {
        for(j=b;j<=b+2;++j)
        {
            if(v[i][j]=='.')
                v[i][j]='!',ok=1;
        }
    }
    for(i=1;i<=9;++i)
    {
        for(j=1;j<=9;++j)
        {
            if(!ok && v[i][j]=='.')
                cout<<'!';
            else
                cout<<v[i][j];
            if(j%3==0)
            {
                cout<<' ';
            }
        }
        if(i%3==0)
            cout<<'\n';
        cout<<'\n';
    }
    return 0;
}