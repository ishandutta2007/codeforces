#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

int n, C[10005];
vector <int> dsk[10005];
int ans=0;

void bfs()
{
	queue <pair <int, int> > Q;
	bool queued[10005];
	for (int i=1; i<=n; i++) queued[i]=0;
	Q.push({1, 0});
	queued[1]=1;
	int v, cl;
	
	while (!Q.empty())
	{
		v=Q.front().first;
		cl=Q.front().second;
		Q.pop();
		if (cl!=C[v])
		{
			ans++;
			cl=C[v];
			
		}
		for (int i=0; i<dsk[v].size(); i++) if (!queued[dsk[v][i]]) 
		{
			Q.push({dsk[v][i], cl});
			queued[dsk[v][i]]=1;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	int t;
	for (int i=2; i<=n; i++) 
	{
		cin>>t;
		dsk[t].push_back(i);
		dsk[i].push_back(t);
	}
	for (int i=1; i<=n; i++) cin>>C[i];
	
	bfs();
	cout<<ans;
}