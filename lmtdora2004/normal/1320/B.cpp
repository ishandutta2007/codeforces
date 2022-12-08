#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, len;
vector<int> adj[200005], adjn[200005];

int dist[200005], a[200005];
bool used[200005];

void bfs(int node)
{
	queue<int> q;
	dist[node]=0;
	used[node]=true;
	q.push(node);
	while(q.size())
	{
		int now=q.front();
		q.pop();
		for(auto i:adj[now])
		{
			if(!used[i])
			{
				used[i]=true;
				dist[i]=dist[now]+1;
				q.push(i);
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		int u, v;
		cin>>u>>v;
		adjn[u].push_back(v);
		adj[v].push_back(u);
	}
	cin>>len;
	int ansl=0, ansn=0;
	for(int i=1; i<=len; i++)
	{
		cin>>a[i];
	}
	bfs(a[len]);
	for(int i=1; i<len; i++)
	{
		int ccnt=0;
		if(dist[a[i]]!=dist[a[i+1]]+1) ansn++;
		for(auto j:adjn[a[i]])
		{
			if(dist[j]==dist[a[i]]-1) ccnt++;
		}
		if(dist[a[i]]!=dist[a[i+1]]+1||ccnt>=2) ansl++;
		//cout<<i<<" "<<ansl<<endl;
	}
	cout<<ansn<<" "<<ansl;
}