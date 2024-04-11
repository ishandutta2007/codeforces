#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const ll mod = 1e9 + 9;

int t_node[maxn] , t_edge[maxn] , p[maxn] , ans;

int root(int v)
{
	return ((p[v] == -1)? v : p[v] = root(p[v]));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(p , -1 , sizeof p);
	fill(t_node , t_node + maxn , 1);
	int n , m;
	cin >> n >> m;
	ans = 1;
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a = root(a - 1) , b = root(b - 1);
		if(a == b)
		{
			t_edge[a]++;
			ans = (ans * 2LL) % mod;
		}
		else
		{
			p[b] = a;
			t_edge[a] += t_edge[b];
			t_edge[b] = 0;
			t_node[a] += t_node[b];
			t_node[b] = 0;
		}
		cout << (ans - 1 + mod) % mod << endl;
	}
}