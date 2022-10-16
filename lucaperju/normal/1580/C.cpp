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
int x[200005];
int y[200005];
struct ura
{
    int l,r,i;
};
vector<ura>v;
int active[200005];
const int bucket=450;
int sp[bucket+1][200005];
int rz[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,t,i,j,n,k;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
            active[b]=i;
        else
        {
            v.push_back({active[b],i-1,b});
            active[b]=0;
        }
    }
    for(i=1;i<=n;++i)
        if(active[i])
            v.push_back({active[i],m,i});
    for(int xx=0;xx<v.size();++xx)
    {
        ura a=v[xx];
        int xc=x[a.i];
        int yc=y[a.i];
        int l=a.l,r=a.r;
        if(bucket<xc+yc)
        {
            /*for(i=l;i<=r;++i)
                if((i-l)%(xc+yc)>=xc)
                    ++rz[i];*/
            for(i=l;i<=r;i=i+xc+yc)
            {
                if(i+xc<=r){
                        sp[1][i+xc]++;
                    sp[1][min(r+1,i+xc+yc)]--;
                }
            }
        }
        else
        {
            for(i=l+xc;i<=min(r,l+xc+yc-1);++i)
            {
                sp[xc+yc][i]++;
                if(i+(xc+yc)*((r-i)/(xc+yc)+1)<=m)
                    sp[xc+yc][i+(xc+yc)*((r-i)/(xc+yc)+1)]--;
            }
        }
    }
    for(j=1;j<=bucket;++j)
    {
        for(i=1;i<=m;++i){
            if(i-j>=1)
                sp[j][i]+=sp[j][i-j];
            rz[i]+=sp[j][i];
        }
    }
    for(i=1;i<=m;++i)
        cout<<rz[i]<<'\n';
    return 0;
}