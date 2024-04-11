#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int v2[1003],v1[1003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,h,k,m,j=0,n,s=0,tt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int mx=3,ok=0;
        for(i=3;i<=n;++i)
        {
            cout<<"? 1 2 "<<i<<'\n';
            cout.flush();
            cin>>v1[i];
            if(v1[i]>v1[mx])
                mx=i;
            if(i>=4 && v1[i]!=v1[i-1])
                ok=1;
        }
        if(ok==0)
        {
            int a=v1[3];
            for(i=4;i<=n;++i)
            {
                cout<<"? 1 3 "<<i<<'\n';
                cout.flush();
                int x;
                cin>>x;
                if(x>a)
                    break;
            }
            if(i<=n)
            {
                cout<<"! 3 "<<i<<'\n';
                cout.flush();
            }
            else
            {
                cout<<"! 1 2\n";
                cout.flush();
            }
            continue;
        }
        int a=v1[3];
        int mx1=2,prec=-1,okk=0;
        for(i=2;i<=n;++i)
        {
            if(i==mx)
                continue;
            cout<<"? 1 "<<mx<<' '<<i<<'\n';
            cout.flush();
            cin>>v2[i];
            if(prec!=-1)
            {
                if(v2[i]!=prec)
                    okk=1;
            }
            prec=v2[i];
            if(v2[i]>v2[mx1])
                mx1=i;
        }
        if(!okk)
            mx1=1;
        cout<<"! "<<mx<<' '<<mx1<<'\n';
        cout.flush();
    }
    return 0;
}