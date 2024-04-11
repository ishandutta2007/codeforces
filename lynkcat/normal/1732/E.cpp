// LUOGU_RID: 91466982
// Lynkcat.
// Problem: E. Location
// Contest: Codeforces - Codeforces Round #830 (Div. 2)
// URL: https://codeforces.com/contest/1732/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
// #define int ll
#define N 50005
using namespace std;
poly G[N];
unsigned inv[N],a[N],b[N],c[N],d[N],ans[N];
int n,q;
unsigned int Inv(unsigned int x)
{
	unsigned int w = 1;
	for (int t=0;t<32;t++)
		if((w*x-1)&((1ll<<(t+1))-1)) w+=1u<<t;
	return w;
}
void BellaKira()
{
	for (int i=2;i<N;i++)
		if (!G[i].size())
			for (int j=i;j<N;j+=i)
				G[j].push_back(i);
	inv[1]=1;
	for (int i=2;i<N;i++)
		if (i&1) inv[i]=Inv(i)*Inv(i);
		else inv[i]=inv[i>>1];
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		cin>>b[i];
	for (int i=1;i<=n;i++)
	{
		int x=__builtin_ctz(a[i]|b[i]);
		c[i]=(a[i]>>x)*inv[__gcd(a[i],b[i])];
		a[i]=x;
		d[i]=__builtin_ctz(b[i]);
	}
	while (q--)
	{
		int opt;
		cin>>opt;
		if (opt==1)
		{
			int l,r,x;
			cin>>l>>r>>x;
			ans[1]=x;
			int len=1;
			for (auto &u:G[x])
			{
				int nw=1;
				while (x%(1ll*len*u)==0)
				{
					for (int i=1;i<=u;i*=2)
						memcpy(ans+i*len+1,ans+1,sizeof(unsigned int )*min(u-i,i)*len);
					nw*=u,len*=u;
					if (u!=2)
						for (int i=nw;i<=len;i+=nw) ans[i]=ans[i]*inv[u];
					else 
						for (int i=nw;i<=len;i+=nw)
							ans[i]>>=1;
				}
			}
			// cout<<"SS"<<endl;
			while (len<50000)
				memcpy(ans+len+1,ans+1,sizeof(unsigned int)*min(50000-len,len)),len=min(len*2,50000);
			// cout<<"TT"<<endl;
			for (int i=l;i<=r;i++)
				c[i]=ans[b[i]];
			unsigned int w=__builtin_ctz(x);
			for (int i=l;i<=r;i++) a[i]=min(w,d[i]);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			unsigned int res=-1;
			for (int i=l;i<=r;i++)	res=min(res,(b[i]*c[i])>>a[i]);
			cout<<res<<'\n';
		}
	}
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}