#include<bits/stdc++.h>
using namespace std;
bool cmp(pair <string, int> a, pair <string, int> b)
{
	return (a.first.size()) < (b.first.size());
}
const int const1 = 1e9 + 7, const2 = 998244353;
vector <vector <int> > g;
vector <bool> used;
vector <vector <int> > dp;
void dfs(int v)
{
	used[v] = 1;
	int sum1 = 1, sum2 = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		dfs(g[v][i]);
		sum1 += dp[g[v][i]][0];
		sum2 += max(dp[g[v][i]][0], dp[g[v][i]][1]);
	}
	dp[v][1] = sum1;
	dp[v][0] = sum2;
}
signed main() {	
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	cout.tie(NULL);
  	int t;
  	cin >> t;
  	vector <int> Pow1(1e6 + 1), Pow2(1e6 + 1);
  	Pow1[0] = Pow2[0] = 1;
  	for(int i = 1; i <= 1e6; i++)
  	{
  		Pow1[i] = 1LL * Pow1[i - 1] * 27 % const1;
  		Pow2[i] = 1LL * Pow2[i - 1] * 27 % const2;
	}
  	while(t--)
  	{
  		int n;
  		cin >> n;
  		vector <pair <string, int> > a(n);
  		int maxlen = 0;
  		for(int i = 0; i < n; i++)
  		{
  			cin >> a[i].first;
  			a[i].second = i;
  			maxlen = max(maxlen, (int)a[i].first.size());
		}
		sort(a.begin(), a.end(), cmp);
		vector <vector <pair <pair <int, int> , pair <int, int> > > > H(maxlen + 1);
		vector <pair <int, int> > Hash(n);
		set <pair <pair <int, int>, int> > s3;
		for(int i = 0; i < n; i++)
		{
			long long hash1 = 0, hash2 = 0;
			long long hash3 = 0, hash4 = 0;
			for(int j = 0; j < a[i].first.size(); j++)
			{
				if(j != 0)
				{
				hash3 = 1LL * (hash3 * 27 + a[i].first[j] - 'a' + 1) % const1;
				hash4 = 1LL * (hash4 * 27 + a[i].first[j] - 'a' + 1) % const2;
				}
				hash1 = 1LL * (hash1 * 27 + a[i].first[j] - 'a' + 1) % const1;
				hash2 = 1LL * (hash2 * 27 + a[i].first[j] - 'a' + 1) % const2;
				H[j + 1].push_back({{hash1, hash2}, {hash3, hash4}});
			}
		}
		set <pair <int, pair <int, int>> > :: iterator it;
		int ind = 0;
		for(int i = 0; i <= maxlen; i++)
		{
			sort(H[i].begin(), H[i].end());
			for(int j = 0; j < H[i].size(); j++)
			{
				if(j == 0 || H[i][j] != H[i][j - 1])
				{
				s3.insert({H[i][j].first, ind});
				ind++;
				}
			}
		}
		g.resize(ind);
		dp.resize(ind, vector <int> (2));
		used.resize(ind);
		ind = 0;
		for(int i = 0; i <= maxlen; i++)
		{
			for(int j = 0; j < H[i].size(); j++)
			{
				if(j == 0 || H[i][j] != H[i][j - 1])
				{
					int res1 = H[i][j].second.first;
					int res2 = H[i][j].second.second;
					set <pair <pair <int, int>, int> > :: iterator it1;
					it1 = s3.lower_bound({{res1, res2}, 0});
					if(it1 != s3.end() && it1 -> first == make_pair((int)res1, (int)res2))
					{
						g[it1 -> second].push_back(ind);
					}
				ind++;
			}
			}
		}
		int ans = 0;
		for(int ind1 = 0; ind1 < ind; ind1++)
		{
			if(!used[ind1])
			{
				dfs(ind1);
				ans += max(dp[ind1][0], dp[ind1][1]);
			}
		}
		for(int i = 0; i < ind; i++)
		{
			g[i].clear();
			used[i] = 0;
		}
		cout << ans << "\n";
	}
    return 0;
}