#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define hash hhhhhh

const int maxn = 3e5 + 20;
const ll mod[2] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const ll base[2] = {3079 , 737};

string s[maxn] , t;

ll hash[maxn][2] , pw[maxn][2] , ht[2] , m , tah = 1 , res;

vector<int> adj[maxn];

void prepare()
{
	pw[0][0] = pw[0][1] = 1;
	for(int i = 1; i < maxn; i++)
		for(int j = 0; j < 2; j++)
			pw[i][j] = (pw[i - 1][j] * base[j]) % mod[j];
}

ll get(int l , int r , int k)
{
	if(l >= r)
		return -1;
	ll ans = hash[r][k] - hash[l][k] * pw[r - l][k];
	ans %= mod[k];
	return (ans + mod[k]) % mod[k];
}

void dfs(int v)
{
//	cout << v + 1 << endl;
	for(auto u : adj[v])
	{
		for(int i = 0; i < (int)s[u].size(); i++)
		{
			bool f = 1;
			for(int j = 0; j < 2; j++)
			{
				hash[tah][j] = (hash[tah - 1][j] * base[j] + s[u][i]) % mod[j];
				if(tah < m || get(tah - m , tah , j) != ht[j])
					f = 0;
			}
			res += f;
			tah++;
		}
		dfs(u);
		for(int i = 1; i <= (int)s[u].size(); i++)
			for(int j = 0; j < 2; j++)
				hash[tah - i][j] = 0;
		tah -= (int)s[u].size();
	}
}

int main()
{
	prepare();
	int n;
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p >> s[i];
		p--;
		adj[p].pb(i);
	}
	cin >> t;
	m = t.size();
	for(int i = 0; i < m ;i++)
		for(int j = 0; j < 2; j++)
			ht[j] = (ht[j] * base[j] + t[i]) % mod[j];
	dfs(0);
	cout << res << endl;
}