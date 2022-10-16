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
int okt=1;
vector<int>v[200005];
vector<int>fel[200005];
int viz[200005],viz1[200005];
char dir[200005];
int ans[200005];
vector<int>vc;
void dfs (int pz)
{
    vc.push_back(pz);
    for(int i=0;i<v[pz].size();++i)
    {
        if(viz[v[pz][i]])
        {
            if(viz[pz]+viz[v[pz][i]]!=3)
                okt=0;
        }
        else
        {
            viz[v[pz][i]]=3-viz[pz];
            dfs(v[pz][i]);
        }
    }
}
int tc;
int poz[200005];
void sortare (int pz, bool inv, int cat)
{
    viz1[pz]=cat;
    for(int i=0;i<v[pz].size();++i)
    {
        if(viz1[v[pz][i]]<cat && ((viz[pz]==fel[pz][i])^inv))
        {
            sortare(v[pz][i],inv,cat);
        }
    }
    poz[pz]=++tc;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,x,y,k,m,j=0,n,tt,p;
  //  cin>>t;
    t=1;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=m;++i)
        {
            int a,b,c;
            cin>>a>>b>>c;
            v[b].push_back(c);
            v[c].push_back(b);
            fel[b].push_back(a);
            fel[c].push_back(a);
        }
        for(i=1;i<=n;++i)
        {
            if(!viz[i])
            {
                vc.clear();
                viz[i]=1;
                dfs(i);
                if(okt==0)
                {
                    cout<<"NO\n";
                    return 0;
                }
                int ok=1;


               // tc=0;
                for(auto j:vc)
                {
                    if(viz1[j]==0)
                        sortare(j,0,1);
                }
                for(auto j:vc)
                {
                    for(int i=0;i<v[j].size();++i)
                    {
                        if((viz[j]==fel[j][i]))
                            if(poz[j]<poz[v[j][i]])
                                ok=0;
                    }
                }
                if(ok)
                {
                    for(auto j:vc)
                    {
                        if(viz[j]==2)
                            dir[j]='L';
                        else
                            dir[j]='R';
                        ans[j]=poz[j];
                    }
                }
                else
                {
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
        cout<<"YES\n";
        for(i=1;i<=n;++i)
        {
            cout<<dir[i]<<' '<<ans[i]<<'\n';
        }
    }
    return 0;
}