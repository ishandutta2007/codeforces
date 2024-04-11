#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize(2)
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
// #define int ll
#define N 200005
using namespace std;
int n,l[N],r[N],ans[N],s[N];
int q;
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
	}
	poly g(2*n+1,0);
	for (int i=0;i<30;i++)
	{
		// map<int,int>s;
		memset(s,0,sizeof(s));
		g.resize(2*n+1);
		int l1=0;
		for (int j=1;j<=n;j++)
		{
			int L=l[j]&((1<<(i))-1);
			int R=r[j]&((1<<(i))-1);
			g[l1++]=L;
			g[l1++]=R;
		}
		g[l1++]=0;
		sort(g.begin(),g.end());
		g.erase(unique(g.begin(),g.end()),g.end());
		for (int j=1;j<=n;j++)
		{
			if ((l[j]>>i)<=(r[j]>>i)-2)
			{
				s[0]++;
				continue;
			}
			int L=l[j]&((1<<(i))-1);
			int R=r[j]&((1<<(i))-1);
			L=lower_bound(g.begin(),g.end(),L)-g.begin();
			R=lower_bound(g.begin(),g.end(),R)-g.begin();
			if ((l[j]>>i)==(r[j]>>i)-1)
			{
				if (g[R]>=g[L]-1)
				{
					s[0]++;
					continue;
				}
				s[0]++;
				s[R+1]--;
				s[L]++;
			} else
			{
				s[L]++;
				s[R+1]--;
			}
		}
		int nw=0;
		for (int j=0;j<=2*n;j++)
		{
			nw+=s[j];
			ans[i]=max(ans[i],nw);
		}
	}
	cin>>q;
	while (q--)
	{
		int x;
		cin>>x;
		int y=__lg(x&(-x));
		// cout<<"?"<<y<<endl;
		cout<<ans[y]<<'\n';
	}
			
			
}
signed main()
{
	IOS;cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}