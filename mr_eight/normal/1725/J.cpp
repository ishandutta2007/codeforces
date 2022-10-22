#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> > e[200005];
int F[200005],g[200005],mx1[200005],mx2[200005],fa[200005];
int ans=0;
void dfs2(int u,int f)
{
	pair<int,int> mx={mx2[u],u},cd={0,0},sd={0,-1};
	vector<pair<int,int> > s;
	for(auto v:e[u])
	{
		if(v.first==f) continue;
		if(mx1[v.first]+v.second>mx.first) sd=cd,cd=mx,mx={mx1[v.first]+v.second,v.first};
		else if(mx1[v.first]+v.second>cd.first) sd=cd,cd={mx1[v.first]+v.second,v.first};
		else if(mx1[v.first]+v.second>sd.first) sd={mx1[v.first]+v.second,v.first};
		s.push_back({F[v.first],v.first});
	}
	if(mx.second==cd.second||mx.second==sd.second||cd.second==sd.second) exit(1);
	sort(s.begin(),s.end());
	for(auto v:e[u])
	{
		if(v.first==f) continue;
		if(v.first!=mx.second) mx2[v.first]=v.second+mx.first;
		else mx2[v.first]=v.second+cd.first;
	}
	for(auto v:e[u])
	{
		if(v.first==f) continue;
		if(v.first!=mx.second&&v.first!=cd.second) g[v.first]=mx.first+cd.first;
		else if(v.first==mx.second) g[v.first]=sd.first+cd.first;
		else g[v.first]=sd.first+mx.first;
		g[v.first]=max(g[v.first],g[u]);
		if(s.back().second!=v.first) g[v.first]=max(g[v.first],s.back().first);
		else if(s.size()>=2) g[v.first]=max(g[v.first],s[s.size()-2].first);
	}
	for(auto v:e[u])
	{
		if(v.first==f) continue;
		dfs2(v.first,u);
		ans=max(ans,g[v.first]+F[v.first]+v.second*2);
	}
}
void dfs(int u,int f)
{
	fa[u]=f;
	vector<int> s;
	for(auto v:e[u])
	{
		if(v.first!=f)
		{
			dfs(v.first,u);
			s.push_back(mx1[v.first]+v.second);
			mx1[u]=max(mx1[u],mx1[v.first]+v.second);
		}
	}
	sort(s.begin(),s.end());
	if(s.size()>=1) F[u]+=s.back();
	if(s.size()>=2) F[u]+=s[s.size()-2];
	for(auto v:e[u])
	{
		if(v.first!=f)
			F[u]=max(F[u],F[v.first]);
	}
	int sum=0;
	ans=max(ans,sum);
}
int n,S=0;
void cl()
{
	for(int i=1;i<=n;i++) e[i].clear();
	memset(F,0,sizeof F);
	memset(g,0,sizeof F);
	memset(mx1,0,sizeof F);
	memset(mx2,0,sizeof F);
	ans=0,S=0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
//	int T;
//	cin >> T;
//	while(T--)
//	{
		cin >> n;
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			cin >> u >> v >> w;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
			S+=w*2;
		}
		dfs(1,0),dfs2(1,0);
		for(int u=1;u<=n;u++)
		{
			vector<int> s;
			for(auto v:e[u])
			{
				if(v.first!=fa[u])
					s.push_back(mx1[v.first]+v.second);
			}
			s.push_back(mx2[u]);
			if(u==1)
			{
		//		cout << s.size() << "*\n";
		//		for(auto t:s) cout << t << "!\n";
			}
			sort(s.begin(),s.end());
			int L=min(4ll,(int)s.size()),sum=0;
			if(s.size())for(int i=(int)s.size()-1;i>=s.size()-L;i--)
			{
				sum+=s[i];
				if(!i) break;
			}
	//		cout << sum << "*\n";
			ans=max(ans,sum);
		}
	//	cout << g[5] << " " << F[1] << " " << F[2]  << " " << g[2] << "\n";
		cout << S-ans << "\n";
		cl();
//	}
	return 0;
}
/*
9
1 2 100
1 3 100
1 4 100
1 5 100
2 6 100
3 7 100
4 8 100
5 9 100
*/