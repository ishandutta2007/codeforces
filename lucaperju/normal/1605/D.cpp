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
vector<int>v[200005];
vector<int>pzs[2];
int lg[200005];
vector<int>care[50];
int ord[50];
int rz[200005];
bool cmp (int a, int b)
{
    return care[a].size()>care[b].size();
}
void dfs (int nod, int t, int p)
{
    pzs[p].push_back(nod);
    for(int i=0;i<v[nod].size();++i)
    {
        if(v[nod][i]==t)
            continue;
        dfs(v[nod][i],nod,1-p);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,i,j,t;
    cin>>t;
    lg[1]=1;
    for(i=2;i<=200000;++i)
        lg[i]=1+lg[i/2];
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
        }
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,-1,0);
        for(i=1;i<=lg[n];++i)
        {
            care[i].clear();
            ord[i]=i;
        }
        for(i=1;i<=n;++i)
            care[lg[i]].push_back(i);
        sort(ord+1,ord+lg[n]+1,cmp);
        for(i=1;i<=lg[n];++i)
        {
            int ind=1;
            if(pzs[0].size()>pzs[1].size())
                ind=0;
            for(j=0;j<care[ord[i]].size();++j)
            {
                rz[pzs[ind].back()]=care[ord[i]][j];
                pzs[ind].pop_back();
            }
        }
        for(i=1;i<=n;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}