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
int val[2][500];
int lsb (int x)
{
    return x&-x;
}
int fv[2][500];
struct ura
{
    int fel,val;
}v[1000];
bool cmp (ura a, ura b)
{
    return fv[a.fel][a.val]>fv[b.fel][a.val];
}
int get_xor(int a, int b, int x, int y)
{
    int s=0;
    for(int i=a;i<b;++i)
        s=(s^val[0][i]);
    for(int i=x;i<y;++i)
        s=(s^val[1][i]);
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,k,m,j=0,tt,p,n,K;
    cin>>n>>K;
    for(i=1;i<n;++i)
    {
        ++fv[0][lsb(i)];
        ++fv[1][lsb(i)];
    }
    for(i=1;i<=n;++i)
    {
        if(fv[0][i])
            v[++j]={0,i};
        if(fv[1][i])
            v[++j]={1,i};
    }
    sort(v+1,v+j+1,cmp);
    k=1;
    for(i=1;i<=j;++i)
    {
        for(int ii=1;ii<n;++ii)
            if(lsb(ii)==v[i].val)
                val[v[i].fel][ii]=k;
        k<<=1;
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<n;++j)
        {
            cout<<val[1][j]<<' ';
        }
        cout<<'\n';
    }
    for(i=1;i<=n-1;++i)
    {
        for(j=1;j<=n;++j)
        {
            cout<<val[0][i]<<' ';
        }
        cout<<'\n';
    }
    cout.flush();
    long long x=1,y=1;
    while(K--)
    {
        int a;
        cin>>a;
        int aa=-1,bb=-1;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
            {
                if(get_xor(min(x,i),max(x,i),min(y,j),max(y,j))==a)
                    aa=i,bb=j;
            }
        assert(aa!=-1);
        cout<<aa<<' '<<bb<<'\n';
        cout.flush();
        x=aa;
        y=bb;
    }
    return 0;
}