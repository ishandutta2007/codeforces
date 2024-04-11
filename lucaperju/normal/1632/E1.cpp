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
vector<int>v[300005];
int t[300005][20],dep[300005],l[300005],r[300005];
int tmp=0;
void dfs (int pz, int tt)
{
    dep[pz]=1+dep[tt];
    l[pz]=++tmp;
    t[pz][0]=tt;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==tt)
            continue;
        dfs(v[pz][i],pz);
    }
    r[pz]=++tmp;
}
bool estr (int a, int b)
{
    if(l[a]<=l[b] && r[b]<=r[a])
        return true;
    return false;
}
int lca (int a, int b)
{
    if(estr(a,b))
        return a;
    if(estr(b,a))
        return b;
    for(int put=18;put>=0;--put)
        if(!estr(t[a][put],b))
            a=t[a][put];
    return t[a][0];
}
int dst (int a, int b)
{
    int c=lca(a,b);
    return dep[a]-dep[c]+dep[b]-dep[c];
}
struct ura
{
    int pz,ad;
}vc[300005];
bool cmp (ura a, ura b)
{
    return a.ad>b.ad;
}
int cat[300005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,i,h,k,m,j=0,n,s=0,tt;
    cin>>tt; /// whyyyyy??? :(
    while(tt--)
    {
        cin>>n;
        for(i=1;i<=n+1;++i)
        {
            v[i].clear();
            cat[i]=0;
            dep[i]=0;
        }
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        tmp=0;
        dfs(1,1);
        for(int put=1;put<=18;++put)
            for(i=1;i<=n;++i)
                t[i][put]=t[t[i][put-1]][put-1];
        for(i=1;i<=n;++i)
            vc[i]={i,dep[i]};
        sort(vc+1,vc+n+1,cmp);
        int lst=-1,mxc=-1;
        i=1;
        for(j=n;j>=1;--j)
        {
            while(i<=n && vc[i].ad==j)
            {
                if(lst==-1)
                    lst=vc[i].pz,mxc=0;
                else
                    mxc=max(mxc,dst(lst,vc[i].pz));
                ++i;
            }
            if(mxc==-1)
                cat[j]=-n;
            else
                cat[j]=(mxc+1)/2+1;
        }
        for(i=1;i<=n;++i)
        {
            k=0;
            int pas=1<<18;
            while(pas)
            {
                if(k+pas<=n && cat[k+pas+1]>k+pas-i)
                    k+=pas;
                pas>>=1;
            }
            cout<<k<<' ';
        }
        cout<<'\n';
    }
    return 0;
}