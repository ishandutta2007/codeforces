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
struct ura
{
    int val,pz;
    char rz;
};
vector<ura>v[100003];
vector<int>val[100003];
vector<int>ed[200003];
map<int,int>lst;
int viz[200003];
void dfs(int pz)
{
    for(int i=0;i<ed[pz].size();++i)
    {
        if(viz[ed[pz][i]])
        {
            assert(viz[pz]+viz[ed[pz][i]]==3);
            continue;
        }
        viz[ed[pz][i]]=3-viz[pz];
        dfs(ed[pz][i]);
    }
}
bool cmp1 (ura a, ura b)
{
    return a.val<b.val;
}
bool cmp2 (ura a, ura b)
{
    return a.pz<b.pz;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,h,k,m,j=0,n,s=0,tt,idk=0,cnt=0;
    cin>>n;
    int okt=1;
    for(i=1;i<=n;++i)
    {
        int nc;
        cin>>nc;
        for(j=1;j<=nc;++j)
        {
            int a;
            cin>>a;
            v[i].push_back({a,j,0});
            val[i].push_back(++idk);
        }
        sort(v[i].begin(),v[i].end(),cmp1);
        for(j=1;j<nc;++j)
        {
            if(v[i][j].val==v[i][j-1].val && v[i][j-1].rz==0)
            {
                v[i][j-1].rz='L';
                v[i][j].rz='R';
            }
        }
        int prec=-1;
        for(j=0;j<nc;++j)
        {
            if(v[i][j].rz)
                continue;
            if(prec==-1)
                prec=j;
            else
            {
                ed[val[i][prec]].push_back(val[i][j]);
                ed[val[i][j]].push_back(val[i][prec]);
                prec=-1;
            }
        }
        if(prec!=-1)
            okt=0;
        for(j=0;j<nc;++j)
        {
            if(v[i][j].rz)
                continue;
            if(lst[v[i][j].val])
            {
                ed[lst[v[i][j].val]].push_back(val[i][j]);
                ed[val[i][j]].push_back(lst[v[i][j].val]);
                lst[v[i][j].val]=0;
                --cnt;
            }
            else
            {
                lst[v[i][j].val]=val[i][j];
                ++cnt;
            }
        }
    }
    if(cnt>0)
        okt=0;
    if(!okt)
    {
        cout<<"NO\n";
        return 0;
    }
    else
        cout<<"YES\n";
    for(i=1;i<=idk;++i)
    {
        if(!viz[i])
        {
            viz[i]=1;
            dfs(i);
        }
    }
    for(i=1;i<=n;++i)
    {
        for(j=0;j<v[i].size();++j)
        {
            if(v[i][j].rz)
            {
                continue;
            }
            else
            {
                if(viz[val[i][j]]==1)
                    v[i][j].rz='L';
                else
                    v[i][j].rz='R';
            }
        }
        sort(v[i].begin(),v[i].end(),cmp2);
        for(j=0;j<v[i].size();++j)
            cout<<v[i][j].rz;
        cout<<'\n';
    }
    return 0;
}