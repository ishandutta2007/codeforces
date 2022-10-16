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
struct ura
{
    int a,pz;
}v[90003];
bool cmp (ura a, ura b)
{
    return a.a>b.a;
}
bool cmp1 (ura a, ura b)
{
    return a.pz<b.pz;
}
int mat[303][303];
int idk[303][303];
vector<pair<int,int> >pzs[90003];
map<int,int>mp;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,n,m,j,k,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        mp.clear();
        for(i=1;i<=n*m;++i)
        {
            cin>>v[i].a;
            mp[v[i].a]=1;
            v[i].pz=i;
        }
        sort(v+1,v+n*m+1,cmp);
        long long cnt=0;
        vector<int>idfk;
        for(auto i : mp)
        {
            idfk.push_back(i.first);
        }
        for(auto i : idfk)
            mp[i]=++cnt;
        for(i=1;i<=n*m;++i)
            v[i].a=mp[v[i].a];
        int k=1;
        for(i=1;i<=n*m;++i)
            pzs[i].clear();
        for(i=n;i>=1;--i)
        {
            for(j=m;j>=1;--j)
            {
                mat[i][j]=0;
                idk[i][j]=v[k].a;
                pzs[v[k].a].push_back(make_pair(i,j));
                ++k;
            }
        }
        sort(v+1,v+n*m+1,cmp1);
        cnt=0;
        for(i=1;i<=n*m;++i)
        {
            pair<int,int> x = pzs[v[i].a].back();
            for(j=1;j<=x.second;++j)
            {
                if(idk[x.first][j]!=v[i].a)
                cnt+=mat[x.first][j];
            }
            mat[x.first][x.second]=1;
            pzs[v[i].a].pop_back();
        }
        cout<<cnt<<'\n';
    }
    return 0;
}