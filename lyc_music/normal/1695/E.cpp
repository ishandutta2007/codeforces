// Lynkcat.
// Problem: E. Ambiguous Dominoes
// URL: https://codeforces.com/contest/1695/problem/E
// Memory Limit: 256 MB
// Time Limit: 8000 ms
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
#define mod 998244353
#define int ll
#define N 2000005
using namespace std;
int vis[N];
int lst[N];
poly G[N];
int n;
poly ans;
int x[N],y[N];
void dfs(int k)
{
	while (G[k].size())
	{
		int now=G[k].back();
		G[k].pop_back();
		dfs(now);
		ans.push_back(now);
	}
		
	// cout<<endl;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		x[n+i]=y[i],y[n+i]=x[i];
		G[x[i]].push_back(y[i]);
		G[y[i]].push_back(x[i]);
	}
	poly up;
	poly down;
	poly upc;
	poly downc;
	poly upd;
	poly downd;
	int len=0;
	for (int i=1;i<=2*n;i++)
	{
		if (!vis[i])
		{
			ans.clear();
			dfs(i);
			// for (auto u:ans) cout<<u<<",";
			// cout<<endl;
			// cout<<"?"<<i<<" "<<ans.size()<<endl;
			if (ans.size()==2) return cout<<-1<<endl,void();
			reverse(ans.begin(),ans.end());
			len+=ans.size()/2;
			int nowlen=ans.size()/2;
			if (nowlen%2==0)
			{
				for (int i=0;i<nowlen;i++)
				{
					up.push_back(ans[i]);
					if (i%2==0)
						upc.push_back('L');
					else upc.push_back('R');
					
					if (i==0||i==nowlen-1)
					{
						upd.push_back('U');
					} else
					{
						if (i%2==1)
							upd.push_back('L');
						else upd.push_back('R');
					}
						
				}
				for (int i=nowlen*2-1;i>=nowlen;i--)
				{
					down.push_back(ans[i]);
					if (i%2==1)
						downc.push_back('L');
					else downc.push_back('R');
					if (i==nowlen*2-1||i==nowlen)
					{
						downd.push_back('D');
					} else
					{
						if (i%2==0)
							downd.push_back('L');
						else downd.push_back('R');
					}
				}
			} else
			{
				for (int i=0;i<nowlen;i++)
				{
					up.push_back(ans[i]);
					if (i==nowlen-1)
					{
						upc.push_back('U');
					} else
					{
						if (i%2==0)
							upc.push_back('L');
						else upc.push_back('R');
					}
					
					if (i==0)
					{
						upd.push_back('U');
					} else
					{
						if (i%2==1)
							upd.push_back('L');
						else upd.push_back('R');
					}
				}
				for (int i=nowlen*2-1;i>=nowlen;i--)
				{
					down.push_back(ans[i]);
					if (i==nowlen)
					{
						downc.push_back('D');
					} else
					{
						if (i%2==1)
							downc.push_back('L');
						else downc.push_back('R');
					}
					
					if (i==nowlen*2-1)
					{
						downd.push_back('D');
					} else
					{
						if (i%2==0)
							downd.push_back('L');
						else downd.push_back('R');
					}
				}
			}
		}
	}
	assert(up.size()==n);
	cout<<2<<" "<<n<<endl;
	for (auto u:up) cout<<u<<" ";
	cout<<endl;
	for (auto u:down) cout<<u<<" ";
	cout<<endl;
	for (auto u:upc) cout<<char(u)<<"";
	cout<<endl;
	for (auto u:downc) cout<<char(u)<<"";
	cout<<endl;
	for (auto u:upd) cout<<char(u)<<"";
	cout<<endl;
	for (auto u:downd) cout<<char(u)<<"";
	cout<<endl;
	
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}