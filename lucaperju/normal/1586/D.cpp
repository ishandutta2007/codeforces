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
int n;
int qc[103];
int query ()
{
    cout<<"? ";
    for(int i=1;i<=n;++i)
        cout<<qc[i]<<' ';
    cout<<'\n';
    cout.flush();
    int a;
    cin>>a;
    return a;
}
int rz[103];
vector<int>vc;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);///
    long long m,q,t,i,j,k;
    cin>>n;
    t=n;
    vc.push_back(n);
    while(t--)
    {
        int nc=0;
        for(i=1;i<=n;++i)
            if(!rz[i])
                ++nc;
        for(i=1;i<=n;++i)
            if(!rz[i])
                qc[i]=1;
        qc[vc[0]]=1+vc.size();
        for(i=1;i<vc.size();++i)
            qc[vc[i]]=nc;
        int a=0;
        if(t)
            a=query();
        if(a!=0)
        {
            vc.push_back(a);
            continue;
        }
        else
        {
            int ncv=nc;
            for(i=vc.size()-1;i>=0;--i)
            {
                rz[vc[i]]=nc--;
                qc[vc[i]]=ncv;
            }
            vc.clear();
            for(i=n;i>=1;--i)
                if(!rz[i])
                    break;
            vc.push_back(i);
        }
    }
    cout<<"! ";
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    cout<<'\n';
    cout.flush();
    return 0;
}