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
#define int ll
#define N 200005
using namespace std;
int n,q,a[N];
poly G[N];
multiset<int>S[N];
int tot;
int siz[N];
void BellaKira()
{
	cin>>n>>q;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		// a[i]=i;
	}
	int ans=0;
	for (int i=1;i<n;i++)
	{
		bool bl=1;
		for(int j=2;j*j<=n/i;j++)
			if((n/i)%j==0)
			{
				bl=0;
				break;
			}
		if (bl&&n%i==0)
		{
			++tot;
			siz[tot]=i;
			G[tot].resize(i);
			for (auto &u:G[tot]) u=0;
			for (int j=0;j<n;j++)
				G[tot][j%i]+=a[j];
			for (auto u:G[tot])
				S[tot].insert(u);
			ans=max(ans,(*S[tot].rbegin())*i);
			// cout<<i<<" "<<ans<<endl;
		}
	}
	// assert(tot<=160);
		// return;
	cout<<ans<<'\n';
	// return;
	while (q--)
	{
		int p,x;
		cin>>p>>x;
		// p=n,x=1;
		ans=0;
		p--;
		for (int i=1;i<=tot;i++)
		{
			// assert(S[i].count(G[i][p%siz[i]]));
			S[i].erase(S[i].find(G[i][p%siz[i]]));
			G[i][p%siz[i]]-=a[p];
		}
		a[p]=x;
		for (int i=1;i<=tot;i++)
		{
			G[i][p%siz[i]]+=a[p];
			// cout<<"?"<<
			S[i].insert(G[i][p%siz[i]]);
			ans=max(ans,(*S[i].rbegin())*siz[i]);
		}
		cout<<ans<<'\n';
	}
	for (int i=1;i<=tot;i++) poly().swap(G[i]),siz[i]=0,multiset<int>().swap(S[i]);
	tot=0;
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}