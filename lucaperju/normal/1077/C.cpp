#include <iostream>
#include <cstring>
using namespace std;

int lgput (long long a, long long exp, long long mod)
{
    long long rez=1;
    while(exp)
        if(exp&1)rez*=a,rez%=mod,--exp;
            else a*=a,a%=mod,exp>>=1;
    rez%=mod;
    return rez;
}
int cmmdc (int a, int b)
{
    int r;
    while(b)r=a%b,a=b,b=r;
    return a;
}
int v[200005];
int main()
{
    long long n,s=0,cr,i,a,b,c,mx1=0,mx2=0,cnt=0,pz1,pz2;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        s+=v[i];
        if(v[i]>mx1)
        {
            pz2=pz1;
            pz1=i;
            mx2=mx1;
            mx1=v[i];
        }
        else
        if(v[i]>mx2)
            mx2=v[i],pz2=i;
    }
    if(n==3 && v[1]==v[2] && v[2]==v[3])
    {
        cout<<3<<'\n'<<1<<' '<<2<<' '<<3;
        return 0;
    }
    else
    if(n==3)
    {
        if(v[1]==v[2])
            cout<<1<<'\n'<<3;
        else
        if(v[1]==v[3])
            cout<<1<<'\n'<<2;
        else
        if(v[3]==v[2])
            cout<<1<<'\n'<<1;
        else
            cout<<0;
        return 0;
    }
    if(mx1==mx2 && s-mx1-mx2==mx2)
    {
        cout<<2<<'\n'<<pz1<<' '<<pz2;
        return 0;
    }
    else
    if(mx1==mx2)
    {
        cout<<0;
        return 0;
    }
    if(s-mx1-mx2==mx2)
        ++cnt;
    for(i=1;i<=n;++i)
    {
        if(v[i]!=mx1)
        {
            if(s-v[i]-mx1==mx1)
                ++cnt;
        }
    }
    cout<<cnt<<'\n';
    if(s-mx1-mx2==mx2)
        cout<<pz1<<' ';
    for(i=1;i<=n;++i)
    {
        if(v[i]!=mx1)
        {
            if(s-v[i]-mx1==mx1)
                cout<<i<<' ';
        }
    }
    return 0;
}