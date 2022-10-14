//

#include <bits/stdc++.h>
#define int long long
#define very_fast std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int siz[15];
vector<int>v[15];
map<vector<int>,int >mp;
map<vector<int>,int >vis;
signed main()
{
	very_fast;
	cin>>n;
	up(i,0,n-1)
	{int x;
		cin>>siz[i];up(j,1,siz[i])cin>>x,v[i].emplace_back(x);
	}
	int m;cin>>m;
	up(i,1,m)
	{
		vector<int>q;
		int x;
		up(i,0,n-1)cin>>x,q.emplace_back(x-1);
		mp[q]=1;
	}
	priority_queue<pair<int,vector<int>>>q;
	vector<int>r;
	int f=0;
	up(i,0,n-1)r.emplace_back(siz[i]-1),f+=v[i][siz[i]-1];
	q.push(make_pair(f,r));
	while(!q.empty())
	{
		pair<int,vector<int>> nw=q.top();q.pop();
		int x=nw.first;
		vector<int>y=nw.second;
		if(vis.find(y)!=vis.end())continue;
		if(mp.find(y)==mp.end())
		{
			for(auto to:y)
			{
				cout<<to+1<<" ";
			}
			goto gg;
		}
		vis[y]=1;
		up(i,0,n-1)
		{
			if(y[i]!=0)
			{
				y[i]--;
				q.push(make_pair(x-v[i][y[i]+1]+v[i][y[i]],y));
				y[i]++;
			}
		}
	}
	gg:;
}//
//