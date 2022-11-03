#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 25e2 + 20;

int a[maxn][maxn] , pos[maxn] , b[maxn][maxn];

vector<int> dsu[maxn];

int main()
{
	int n;
	cin >> n;

	vector<pair<int , pair<int , int> > > edge;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			if(i == j && a[i][j])
				return cout << "NOT MAGIC" << endl , 0;

			edge.pb({a[i][j] , {i , j}});
		}

	for(int i = 0; i < n; i++)
		dsu[i].pb(i) , pos[i] = i;

	sort(edge.begin() , edge.end());

	for(auto e : edge)
	{
		int v = pos[e.second.first] , u = pos[e.second.second];
		if(v == u)
			continue;

		for(auto x : dsu[v])
			for(auto y : dsu[u])
				b[x][y] = b[y][x] = e.first;

		if(dsu[v].size() > dsu[u].size())
			swap(v , u) , dsu[v].swap(dsu[v]);

		for(auto x : dsu[v])
			pos[x] = u , dsu[u].pb(x);
		dsu[v].clear();
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] != b[i][j])
				return cout << "NOT MAGIC" << endl , 0;

	cout << "MAGIC" << endl;
}