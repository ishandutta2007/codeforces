#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
bitset<2048>gauss[2048];
vector<int>v[2003];
int rz[2003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,n,m,a,b,j,k;
    long long s=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            gauss[i].reset();
        }
        for(i=1;i<=m;++i)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
            gauss[a][b]=gauss[b][a]=true;
        }
        int ok=1;
        for(i=1;i<=n;++i)
        {
            if(v[i].size()%2==1)
            {
                ok=0;
                gauss[i][i]=gauss[i][n+1]=true;
            }
        }
        if(ok)
        {
            cout<<"1\n";
            for(i=1;i<=n;++i)
                cout<<1<<' ';
            cout<<'\n';
            continue;
        }
        cout<<"2\n";
        for(i=1;i<=n;++i)
        {
            rz[i]=1;
            for(j=1;j<=n;++j)
                if(gauss[i][j])
                    break;
            if(j==n+1) continue;
            int pz=j;
            for(j=1;j<=n;++j)
                if(i!=j && gauss[j][pz])
                    gauss[j]^=gauss[i];
        }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                if(gauss[i][j])
                    break;
            if(j!=n+1 && gauss[i][n+1])
                rz[j]=2;
        }
        for(i=1;i<=n;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}