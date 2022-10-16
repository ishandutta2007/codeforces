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
int a[200005],b[200005];
vector<int>v[200005];
vector<int>v1[200005];
int tc=0,ord[200005],viz[200005],pz[200005],efol[200005],fv[200005];
int smn[200005];
int stk[200005];
void sortaret (int nod, int fara, int cat)
{
    viz[nod]=cat;
    for(int i=0;i<v[nod].size();++i)
    {
        int nn=v[nod][i];
        if(viz[nn]==cat || nn==fara)
            continue;
        sortaret(v[nod][i],fara,cat);
    }
    ord[nod]=++tc;
}
bool findcycle (int nod, int obj)
{
    stk[++tc]=nod;
    viz[nod]=1;
    for(int i=0;i<v[nod].size();++i)
    {
        if(v[nod][i]==obj)
            return true;
        if(!viz[v[nod][i]])
            if(findcycle(v[nod][i],obj))
                return true;
    }
    --tc;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,k,m,j=0,n,tt,p;
    cin>>t;
    //t=1;
    while(t--)
    {
        cin>>n;
        tc=0;
        for(i=1;i<=n;++i)
        {
            efol[i]=0;
            smn[i]=0;
            pz[i]=0;
            fv[i]=0;
            viz[i]=ord[i]=stk[i]=0;
            v[i].clear();
            v1[i].clear();
            cin>>a[i];
        }
        for(i=1;i<=n;++i)
        {
            cin>>b[i];
            ++fv[b[i]];
            efol[b[i]]=1;
            v[b[i]].push_back(a[i]);
            v1[a[i]].push_back(b[i]);
        }
        int mx=0;
        for(i=1;i<=n;++i)
        {
            mx=max(mx,fv[i]);
        }
        for(i=1;i<=n;++i)
            if(fv[a[i]]==mx)
                break;
        int idk=a[i];
        for(i=1;i<=n;++i)
                {
                    if(viz[i]<=1 && efol[i])
                    {
                        sortaret(i,idk,2);
                    }
                }
                int ok=1;
                for(i=1;i<=n;++i)
                {
                    for(j=0;j<v[i].size();++j)
                    {
                        if(i==idk || v[i][j]==idk || !efol[i] || !efol[v[i][j]])
                            continue;
                        if(ord[i]<=ord[v[i][j]])
                            ok=0;
                    }
                }
        if(ok)
            cout<<"AC\n";
        else
            cout<<"WA\n";
    }
    return 0;
}