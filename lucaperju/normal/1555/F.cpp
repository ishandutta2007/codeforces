/// bs D/E
#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
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
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int aib[600005][2];
int lsb(int x)
{
    return x&-x;
}
int qry (int pz, int fel)
{
    --fel;
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        rz+=aib[i][fel];
    return rz;
}
void upd (int pz, int fel, int val)
{
    --fel;
    for(int i=pz;i<=600000;i+=lsb(i))
        aib[i][fel]+=val;
}
int t[300005];
int tata (int pz)
{
    if(t[pz]==pz || t[pz]==0)
        return pz;
    return t[pz]=tata(t[pz]);
}
vector<int>v[300005];
int stramos[300005][19];
struct query
{
    int a,b,c;
}qs[500005];
int viz[300005];
int in[300005],out[300005],tc=0;
void dfs (int pz, int tt)
{
    viz[pz]=1;
    in[pz]=++tc;
    stramos[pz][0]=tt;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==tt)
            continue;
        dfs(v[pz][i],pz);
    }
    out[pz]=++tc;
}
bool estr (int a, int b)
{
    if(in[a]<in[b] && out[b]<out[a])
        return true;
    return false;
}
int getstr (int a, int b)
{
    if(estr(a,b))
        return a;
    if(estr(b,a))
        return b;
    int pas=18;
    while(pas>=0)
    {
        if(!estr(stramos[a][pas],b))
            a=stramos[a][pas];
        --pas;
    }
    return stramos[a][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,j,k,m,n;
    cin>>n>>m;
    for(i=1;i<=m;++i)
        cin>>qs[i].a>>qs[i].b>>qs[i].c;
    for(i=1;i<=m;++i)
    {
        if(tata(qs[i].a)!=tata(qs[i].b))
        {
            t[tata(qs[i].a)]=tata(qs[i].b);
            v[qs[i].a].push_back(qs[i].b);
            v[qs[i].b].push_back(qs[i].a);
        }
    }
    for(i=1;i<=n;++i)
        if(!viz[i])
            dfs(i,i);
    for(int put=1;put<=18;++put)
        for(int i=1;i<=n;++i)
            stramos[i][put]=stramos[stramos[i][put-1]][put-1];
    for(i=1;i<=n;++i)
        t[i]=0;
    for(int qc=1;qc<=m;++qc)
    {
        int a=qs[qc].a,b=qs[qc].b,c=qs[qc].c;
        if(tata(a)!=tata(b))
        {
            if(estr(a,b))
            {
                upd(in[b],1,1*c);
                upd(out[b],1,-1*c);
            }
            else
            {
                assert(estr(b,a));
                upd(in[a],1,1*c);
                upd(out[a],1,-1*c);
            }
            t[tata(a)]=tata(b);
            cout<<"YES\n";
            continue;
        }
        int str=getstr(a,b);
        if(qry(in[a],2)+qry(in[b],2)-qry(in[str],2)*2 != 0)
        {
            cout<<"NO\n";
            continue;
        }
        if((qry(in[a],1)+qry(in[b],1) + c)%2 == 0)
        {
            cout<<"NO\n";
            continue;
        }
        while(a!=str)
        {
            upd(in[a],2,1);
            upd(out[a],2,-1);
            a=stramos[a][0];
        }
        while(b!=str)
        {
            upd(in[b],2,1);
            upd(out[b],2,-1);
            b=stramos[b][0];
        }
        cout<<"YES\n";
    }
    return 0;
}