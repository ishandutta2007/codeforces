#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
//*
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
/*/
int v[100005];
int rz[100005];
int fv[20003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);///
    long long n,m,q,t,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            rz[i]=0;
        }
        for(i=1;i<=10000+10001;++i)
            fv[i]=0;
        if(n%2==0)
        {
            for(i=1;i<=n;i+=2)
            {
                cout<<-v[i+1]<<' '<<v[i]<<' ';
            }
            cout<<'\n';
            continue;
        }
        for(i=1;i<=n;++i)
            ++fv[v[i]+10001];
        int ok=0;
        for(i=1;i<=10000+10001;++i)
            if(fv[i]>=3)
            {
                ok=1;
                break;
            }
        if(!ok)
        {
            if(-v[2]-v[3]!=0)
                cout<<-v[2]-v[3]<<' '<<v[1]<<' '<<v[1]<<' ';
            else if(-v[1]-v[3]!=0)
                cout<<v[2]<<' '<<-v[1]-v[3]<<' '<<v[2]<<' ';
            else
                cout<<v[3]<<' '<<v[3]<<' '<<-v[2]-v[1]<<' ';
            for(i=4;i<=n;i+=2)
                cout<<-v[i+1]<<' '<<v[i]<<' ';
            cout<<'\n';
            continue;
        }
        int vc[]={2,-1,-1};
        int k=0,val=i-10001;
        for(i=1;i<=n;++i)
        {
            if(v[i]==val && k<=2)
                rz[i]=vc[k++];
        }
        k=-1;
        for(i=1;i<=n;++i)
        {
            if(rz[i])
                continue;
            if(k==-1)
                k=i;
            else
            {
                rz[k]=-v[i];
                rz[i]=v[k];
                k=-1;
            }
        }
        for(i=1;i<=n;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
}