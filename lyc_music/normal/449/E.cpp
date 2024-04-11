// Lynkcat.
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 5000005
using namespace std;
int n,m,inv30,inv2,inv6;
int s[N],pr[N],cnt,phi[N];
int vis[N];
int s1[N],s2[N];
int quickPower(int x,int y)
{
    int res=1;
    while (y)
    {
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int calc(int x)
{
    return (1+x)*x%mod*inv6%mod*(2*x+1)%mod;
}
void BellaKira()
{
    cin>>n>>m;
    if (n>m) swap(n,m);
    cout<<(s[n]*((m*n+m+n+1)%mod)%mod-s1[n]*(n+m+2)%mod+mod+s2[n])%mod<<endl;
}
signed main()
{
    // freopen("count.in","r",stdin);
    // freopen("count.out","w",stdout);
    IOS;
    inv2=quickPower(2,mod-2);
    inv6=quickPower(6,mod-2);
    for (int i=2;i<=5000000;i++)
    {
        if (!vis[i])
        {
            pr[++cnt]=i;
            phi[i]=i-1;
        }
        for (int j=1;j<=cnt&&pr[j]*i<=5000000;j++)
        {
            vis[pr[j]*i]=1;
            if (i%pr[j]==0)
            {
                phi[i*pr[j]]=phi[i]*pr[j];
                break;
            } else phi[i*pr[j]]=phi[i]*(pr[j]-1);
        }
    }
    phi[1]=1;
    for (int i=1;i<=5000000;i++)
        for (int j=i,x=phi[i];j<=5000000;j+=i,x=(x+phi[i])%mod)
            s[j]=(s[j]+x)%mod;
    for (int i=1;i<=5000000;i++)
    {
        s[i]=s[i]*2%mod;
        s[i]=(s[i]+i*i%mod*i%mod-2*i%mod*i%mod+mod)%mod;
        s[i]=(s[i]-i*(i-1)%mod*i%mod+mod)%mod;
        s[i]=(s[i]+calc(i-1)*2%mod)%mod;
        
        s1[i]=(s1[i-1]+s[i]*i%mod)%mod;
        s2[i]=(s2[i-1]+s[i]*i%mod*i%mod)%mod;
        s[i]=(s[i-1]+s[i])%mod;
    }
	int T=1;
    cin>>T;
	while (T--)
	{
		BellaKira();
	}
}