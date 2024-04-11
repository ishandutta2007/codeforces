// Lynkcat.
// Problem: F. MCMF?
// URL: https://codeforces.com/contest/1682/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// -----------------------------------------------

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
#define N 200005
using namespace std;
int n,q,a[N],b[N],c[N];
int s[N],S[N];
int Ans[N];
poly G;
vector<pa>P1[N];
poly P[N];
poly Q[N];
int L[N],R[N];
struct BIT
{
	int tr[N];
	void upd(int x,int y)
	{
		y%=mod;
		while (x<=n)
		{
			tr[x]=(tr[x]+y)%mod;
			x+=x&-x;
		}
	}
	int qry(int x)
	{
		int res=0;
		while (x)
		{
			res=(res+tr[x])%mod;
			x-=x&-x;
		}
		return res;
	}
}t[3];
void BellaKira()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i],s[i]=s[i-1]+b[i],c[i]=a[i]*(b[i]+mod)%mod;
	for (int i=1;i<=n;i++)
		G.push_back(s[i]);
	sort(G.begin(),G.end());
	for (int i=0;i<=n;i++)
	{
		S[i]=lower_bound(G.begin(),G.end(),s[i])-G.begin()+1;
	}
	for (int i=1;i<=n;i++)
		if (b[i]<0)
		{
			int x=S[i],y=S[i-1];
			P[x].push_back(i);
			t[0].upd(i,mod-c[i]);
			if (y>x)
			{
				P1[x].push_back(mp(i,1));
				P1[y].push_back(mp(i,mod-1));
			}
		} else
		if (b[i]>0)
		{
			int x=S[i],y=S[i-1];
			P[x+1].push_back(i);
			t[0].upd(i,mod-c[i]);
			if (y<x)
			{
				P1[y+1].push_back(mp(i,1));
				P1[x+1].push_back(mp(i,mod-1));
			}
		}
	for (int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		Q[S[l-1]].push_back(i);
		L[i]=l,R[i]=r;
	}
	for (int i=1;i<=n;i++)
	{
		for (auto u:P[i])
		{
			t[0].upd(u,c[u]*2%mod);
		}
		for (auto [u,v]:P1[i])
		{
			if (b[u]<0)
			{
				t[0].upd(u,v*(s[u-1]%mod+mod)%mod*2%mod*a[u]%mod);
				t[1].upd(u,mod-v*2%mod*a[u]%mod);
			} else
			{
				t[0].upd(u,mod-v*(s[u-1]%mod+mod)%mod*2%mod*a[u]%mod);
				t[1].upd(u,v*2%mod*a[u]%mod);
			}
		}
		for (auto u:Q[i])
		{
			Ans[u]=(t[0].qry(R[u])-t[0].qry(L[u]-1)+mod)%mod;
			Ans[u]=(Ans[u]+(t[1].qry(R[u])-t[1].qry(L[u])+mod)%mod*(s[L[u]-1]%mod+mod)%mod)%mod;
		}
	}
	for (int i=1;i<=q;i++) cout<<Ans[i]<<endl;
	
	// for (int i=1;i<=q;i++)
	// {
		// int l,r;
		// l=L[i],r=R[i];
		// int x=0;
		// int ans=0;
		// for (int j=l;j<=r;j++)
			// if (b[j]<0)
			// {
				// if (s[j]>s[l-1]) ans-=c[j];
				// else
				// {
					// ans+=c[j];
					// if (s[j-1]>s[l-1]) 
					// {
						// ans+=s[j-1]*2*a[j];
						// ans-=s[l-1]*2*a[j];
					// }
				// }
			// } else
			// {
				// if (s[j]<s[l-1]) ans+=b[j]*a[j];
				// else 
				// {
					// ans-=b[j]*a[j];
					// if (s[j-1]<s[l-1]) 
					// {
						// ans-=s[j-1]*2*a[j];
						// ans+=s[l-1]*2*a[j];
					// }
				// }
			// }
		// cout<<ans%mod<<endl;
	// }
				
			
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}