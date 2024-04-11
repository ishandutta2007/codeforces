// Lynkcat.
// Problem: E. Swap and Maximum Block
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms

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
#define mod 998244353
#define int ll
#define N 1000005
using namespace std;
int n,a[N],b[N];
int f[512],pre[512][512],suf[512][512],sum[512][512];
int Pre[N],Suf[N],Sm[N];
int q;
mt19937_64 rnd(time(0));
void BellaKira()
{
	cin>>n;
	for (int i=0;i<(1<<n);i++) cin>>a[i];
	if (n<=9)
	{
		for (int st=0;st<(1<<n);st++)
		{
			for (int i=0;i<(1<<n);i++) b[i]=a[i];
			for (int i=0;i<(1<<n);i++)
			{
				int o=i^st;
				if (o>i) swap(b[i],b[o]);
			}
			f[st]=0;
			int o=0;
			for (int i=0;i<(1<<n);i++)
			{
				f[st]=max(f[st],b[i]-o);
				b[i+1]+=b[i];
				o=min(o,b[i]);
			}
		}
		cin>>q;
		int now=0;
		while (q--)
		{
			int k;cin>>k;
			now^=(1<<k);
			cout<<f[now]<<endl;
		}
	} else
	{
		for (int st=0;st<(1<<9);st++)
		{
			for (int i=0;i<(1<<n);i++) b[i]=a[i];
			for (int i=0;i<(1<<n);i++)
			{
				int o=i^st;
				if (o>i) swap(b[i],b[o]);
			}
			for (int i=0;i<(1<<n);i+=(1<<9))
			{
				int x=0;
				for (int j=i;j<i+(1<<9);j++)
				{
					x+=b[j];
					pre[st][i/(1<<9)]=max(pre[st][i/(1<<9)],x);
				}
				sum[st][i/(1<<9)]=x;
				x=0;
				for (int j=i+(1<<9)-1;j>=i;j--)
				{
					x+=b[j];
					suf[st][i/(1<<9)]=max(suf[st][i/(1<<9)],x);
				}
				x=0;
				int o=0;
				for (int j=i;j<i+(1<<9);j++)
				{
					x+=b[j];
					f[st]=max(f[st],x-o);
					o=min(o,x);
				}
			}
		}
		int now=0;
		cin>>q;
		while (q--)
		{
			int k;cin>>k;
			now^=(1<<k);
			int len=(1<<n)/(1<<9);
			int nw=(now&((1<<9)-1));
			int ans=f[nw];
			// cout<<"?"<<ans<<endl;
			for (int i=0;i<len;i++)
			{
				Pre[i]=pre[nw][i];
				Suf[i]=suf[nw][i];
				Sm[i]=sum[nw][i];
			}
			int t=9;
			while (len>1)
			{
				for (int i=0;i<len;i+=2)
				{
					int x=i,y=i+1;
					if ((now>>t)&1)
					{
						swap(x,y);
					}
					int np=0,ns=0,all=0;
					np=max(Pre[x],Sm[x]+Pre[y]);
					ns=max(Suf[y],Sm[y]+Suf[x]);
					ans=max(ans,Suf[x]+Pre[y]);
					all=Sm[x]+Sm[y];
					Pre[i/2]=np,Suf[i/2]=ns,Sm[i/2]=all;
				}
				len/=2;
				t++;
			}
			cout<<ans<<endl;
		}
	}	
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}