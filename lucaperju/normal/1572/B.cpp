#include <bits/stdc++.h>

using namespace std;

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
int v[200005];
vector<int>rz;
vector<int>pzs;
void upd (int pz)
{
    int val=(v[pz]^v[pz+1]^v[pz+2]);
    v[pz]=v[pz+1]=v[pz+2]=val;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,n,m,r,s,j,q;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            cnt+=v[i];
        }
        if(cnt&1)
        {
            cout<<"NO\n";
            continue;
        }
        pzs.clear();
        rz.clear();
        for(i=1;i<=n;++i)
        {
            if(v[i])
                pzs.push_back(i);
        }
        v[0]=v[n+1]=1;
        for(i=0;i<pzs.size();i+=2)
        {
            int a=pzs[i];
            int b=pzs[i+1];
            if((b-a)%2==0)
            {
                for(j=a;j<b;j+=2)
                {
                    upd(j);
                    rz.push_back(j);
                }
                for(j=b-4;j>=a;j-=2)
                {
                    upd(j);
                    rz.push_back(j);
                }
            }
            else
            {
                if(v[a-1]==0)
                {
                    for(j=a;j<b-1;j+=2)
                    {
                        upd(j);
                        rz.push_back(j);
                    }
                    for(j=a-1;j<=b-2;j+=2)
                    {
                        upd(j);
                        rz.push_back(j);
                    }
                }
            }
        }
        int ok=1;
        for(i=pzs.size()-1;i>=0;i-=2)
        {
            int b=pzs[i];
            int a=pzs[i-1];
            if(v[a]==0)
                continue;
            assert((b-a)%2==1);
            if(v[b+1]!=0)
                ok=0;
            for(j=b-2;j>a;j-=2)
            {
                upd(j);
                rz.push_back(j);
            }
            for(j=b-1;j>=a;j-=2)
            {
                upd(j);
                rz.push_back(j);
            }
        }
        if(!ok)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        cout<<rz.size();
        cout<<'\n';
        for(i=0;i<rz.size();++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}