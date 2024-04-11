#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
const long long mod = 998244353;

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
char v[1000003];
int sa[1000003],sb[1000003],sc[1000003];
bool eok (int l, int r)
{
    --l;
    int a=sa[r]-sa[l];
    int b=sb[r]-sb[l];
    int c=sc[r]-sc[l];
    if(a>b && a>c)
        return true;
    return false;
}
vector<int>pzs;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int s=0;
        pzs.clear();
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            sa[i]=sb[i]=sc[i]=0;
            if(v[i]=='a')
            {
                ++sa[i];
                pzs.push_back(i);
            }
            if(v[i]=='b')
                ++sb[i];
            if(v[i]=='c')
                ++sc[i];
            sa[i]+=sa[i-1];
            sb[i]+=sb[i-1];
            sc[i]+=sc[i-1];
        }
        if(pzs.size()<=1)
        {
            cout<<"-1\n";
            continue;
        }
        int rz=n+1;
        for(i=0;i<pzs.size();++i)
        {
            for(j=i+1;j<min((long long)pzs.size(),i+5);++j)
            {
                if(eok(pzs[i],pzs[j]))
                    rz=min(rz,pzs[j]-pzs[i]+1);
            }
        }
        if(rz==n+1)
            cout<<"-1\n";
        else
            cout<<rz<<'\n';
    }
    return 0;
}