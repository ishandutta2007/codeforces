#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
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
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1;
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
/*
for(i=1;i<=n;++i)
*/
vector <int> v[200003];
int st1[200003],st0[200003];
char c[200003];
int main()
{
    long long i,j,n,a,b,mx=-9999999999999,mn=9999999999999,k,mnpz,cnt=0,k1=0,k0=0;
    cin>>c;
    n=strlen(c);
    for(i=0;i<n;++i)
    {
        if(c[i]=='0')
        {
            if(k1)
            {
                v[st1[k1]].push_back(i);
                st0[++k0]=st1[k1];
                --k1;
            }
            else
            {
                v[++cnt].push_back(i);
                st0[++k0]=cnt;
            }
        }
        else
        {
            if(!k0)
            {
                cout<<-1;
                return 0;
            }
            else
            {
                v[st0[k0]].push_back(i);
                st1[++k1]=st0[k0];
                --k0;
            }
        }
    }
    if(k1)
    {
        cout<<-1;
        return 0;
    }
    cout<<cnt<<'\n';
    for(i=1;i<=cnt;++i)
    {
        cout<<v[i].size()<<' ';
        for(j=0;j<v[i].size();++j)
            cout<<v[i][j]+1<<' ';
        cout<<'\n';
    }
    return 0;
}