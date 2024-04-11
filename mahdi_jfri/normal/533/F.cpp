#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
const int S = 26;
const int P = 2;
const ll mod[P] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const ll base[P] = {3079 , 737};

vector<int> ans , adj[S];

ll ht[S][P] , pw[maxn][P] , hs[S][P];

int pos[S];

void prepare()
{
	pw[0][0] = pw[0][1] = 1;
	for(int i = 1; i < maxn; i++)
		for(int j = 0; j < P; j++)
			pw[i][j] = (pw[i - 1][j] * base[j]) % mod[j];
	for(int i = 0; i < S; i++)
		pos[i] = -1;
}

bool check()
{
	for(int i = 0; i < S; i++)
	{
		sort(adj[i].begin() , adj[i].end());
		adj[i].resize(unique(adj[i].begin() , adj[i].end()) - adj[i].begin());
		if(adj[i].size() > 1)
			return 0;
	}
	return 1;
}

int main()
{
	prepare();
	int n , m;
	string s , t;
	cin >> n >> m >> s >> t;

	for(int i = 0; i < m; i++)
		for(int j = 0; j < S; j++)
			for(int k = 0; k < P; k++)
				ht[j][k] = (ht[j][k] * base[k] + (t[i] == (j + 'a'))) % mod[k];
	
	for(int i = 0; i < n; i++)
	{
		pos[s[i] - 'a'] = i;
		for(int j = 0; j < S; j++)
			for(int k = 0; k < P; k++)
				hs[j][k] = (hs[j][k] * base[k] + (s[i] == (j + 'a'))) % mod[k];
		if(i + 1 < m)
			continue;
		if(i >= m)
			for(int k = 0; k < P; k++)
			{
				hs[s[i - m] - 'a'][k] -= pw[m][k] - mod[k];
				hs[s[i - m] - 'a'][k] %= mod[k];
			}
		for(int j = 0; j < S; j++)
			adj[j].clear();
		for(int j = 0; j < S; j++)
			if(pos[j] > i - m)
			{
				adj[j].pb(t[pos[j] - i + m - 1] - 'a');
				adj[t[pos[j] - i + m - 1] - 'a'].pb(j);
			}
		if(!check())
			continue;
		bool f = 1;
		for(int j = 0; j < S; j++)
			if(pos[j] > i - m)
				for(int k = 0; k < P; k++)
					if(hs[j][k] != ht[adj[j][0]][k])
						f = 0;
		if(f)
			ans.pb(i - m + 2);
	}
	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	cout << endl;
}