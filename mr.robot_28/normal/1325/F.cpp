#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> v[100005], s;
int sq, dep[100005];
bool marked[100005];
void dfs(int node)
{
	s.push_back(node);
	dep[node] = s.size();
	for(int i = 0; i < v[node].size(); i++)
	{
		int u = v[node][i];
		if(!dep[u])
		{
			dfs(u);
		}
		else if(dep[node] - dep[u] + 1 >= sq)
		{
			cout << 2 << "\n";
			cout << dep[node] - dep[u] + 1 << "\n";
			for(int i = dep[u] - 1; i < dep[node]; i++)
			{
				cout << s[i] << " ";
			}
			exit(0);
		}
	}
	if(!marked[node])
	{
		for(int i = 0; i < v[node].size(); i++)
		{
			marked[v[node][i]] = 1;
		}
	}
	s.pop_back();
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	while(sq * sq < n)
	{
		sq++;
	}
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << 1 << "\n";
	for(int i = 1; sq; i++)
	{
		if(!marked[i])
		{
			cout << i << " ";
			sq--;
		}
	}
	return 0;
}