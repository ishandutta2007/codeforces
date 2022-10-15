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
#define N 100005
using namespace std;
int n,m,q;
multiset<int>S[N],G[N];
void BellaKira()
{
	cin>>n>>m>>q;
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		S[x].insert(y);
		G[y].insert(x);
	}
	int x=1,y=1;
	int U=0,D=n+1,L=0,R=m+1;
	int ans=1;
	int o=0;
	while (1)
	{
		auto it=S[x].lower_bound(y);
		if (it!=S[x].end()) R=min(R,(*it));
		R--;
		if (o&&R==y) break;
		ans+=R-y;
		y=R;
		U=max(U,x);
		// cout<<x<<" "<<y<<endl;
		
		it=G[y].lower_bound(x);
		if (it!=G[y].end()) D=min(D,(*it));
		D--;
		if (o&&D==x) break;
		ans+=D-x;
		x=D;R=min(R,y);
		// cout<<x<<" "<<y<<endl;
		
		it=S[x].lower_bound(y);
		if (it!=S[x].begin())
		{
			it--;
			L=max(L,(*it));
		}
		L++;
		if (L==y) break;
		ans+=y-L;
		y=L;
		// cout<<x<<" "<<y<<endl;
		D=min(D,x);
		
		it=G[y].lower_bound(x);
		if (it!=G[y].begin())
		{
			it--;
			U=max(U,(*it));
		}
		U++;
		if (U==x) break;
		ans+=x-U;
		x=U;
		// cout<<x<<" "<<y<<endl;
		L=max(L,y);
		
		o++;
	}
	if (ans==n*m-q) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
		
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