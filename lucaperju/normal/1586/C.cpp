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
char v[2][1000003];
int fv[1000003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);///
    long long n,m,q,t,i,j,k;
    cin>>n>>m;
    if(n==1 || m==1)
    {
        for(i=1;i<=n*m;++i)
        {
            char c;
            cin>>c;
        }
        cin>>q;
        while(q--)
        {
            cout<<"YES\n";
        }
        return 0;
    }
    int p=1,c=0;
    cin>>(v[1]+1);
    for(i=2;i<=n;++i)
    {
        c=i%2;
        p=1-c;
        cin>>(v[c]+1);
        for(j=1;j<m;++j)
            if(v[c][j]=='X' && v[p][j+1]=='X')
                fv[j]=1;
    }
    for(i=1;i<=m;++i)
        fv[i]+=fv[i-1];
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<"YES\n";
            continue;
        }
        --b;
        if(fv[b]-fv[a-1]>0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}