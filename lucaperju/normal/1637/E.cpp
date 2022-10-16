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
unordered_map<int,int>fv;
unordered_map<int,int>idk;
unordered_map<int,short>banned[300005];
unordered_map<int,int>pz;
int v[300005];
vector<int>vals[300005];
vector<int>fvs;
int a[300005],b[300005];
long long check (long long a, long long b)
{
    if(a>b)
        swap(a,b);
    if(a==b)
        return 0;
    if(banned[idk[a]][idk[b]])
        return 0;
    return (a+b)*1LL*(fv[a]+fv[b]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,h,k,m,j=0,n,s=0,tt;
    cin>>t;
    while(t--)
    {
        fv.clear();
        idk.clear();
        pz.clear();
        fvs.clear();
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            banned[i].clear();
            vals[i].clear();
        }
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        for(i=1;i<=n;++i)
            ++fv[v[i]];
        for(i=1;i<=n;++i)
        {
            if(v[i]!=v[i-1])
                idk[v[i]]=1+idk[v[i-1]];
        }
        for(i=1;i<=n;++i)
        {
            if(v[i]!=v[i-1])
            {
                vals[fv[v[i]]].push_back(v[i]);
                pz[v[i]]=(int)vals[fv[v[i]]].size()-1;
            }
        }
        for(i=1;i<=m;++i)
        {
            cin>>a[i]>>b[i];
            banned[idk[a[i]]][idk[b[i]]]=1;
        }
        for(i=1;i<=n;++i)
            if(vals[i].size())
                fvs.push_back(i);
        long long ans=0;
        for(i=0;i<fvs.size();++i)
            for(j=i;j<fvs.size();++j)
            {
                if(i==j)
                {
                    if(vals[fvs[i]].size()==1)
                        continue;
                    ans=max(ans,check(vals[fvs[i]][(int)vals[fvs[i]].size()-1],vals[fvs[i]][(int)vals[fvs[i]].size()-2])); /// fun
                }
                else
                {
                    ans=max(ans,check(vals[fvs[i]][(int)vals[fvs[i]].size()-1],vals[fvs[j]][(int)vals[fvs[j]].size()-1])); /// fun
                }
            }
        for(i=1;i<=m;++i)
        {
            int x=a[i],y=b[i];
            int px=pz[x],py=pz[y];
            int vx=fv[x],vy=fv[y];
            if(px!=0)
                ans=max(ans,check(vals[vx][px-1],vals[vy][py]));
            if(py!=0)
                ans=max(ans,check(vals[vx][px],vals[vy][py-1]));
        }
        cout<<ans<<'\n';
    }
    return 0;
}