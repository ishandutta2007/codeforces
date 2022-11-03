#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 4e4 + 20;
const int maxk = 1e3 + 20;
const int maxb = 17;
const int mod = 1e9 + 7;
const int p = 1e7 + 19;

ll dp[maxb][maxk] , a[maxn];

int st[maxn] , ft[maxn] , w[maxn] , k;

bool is[maxn];

vector<int> x[maxn * 4];

void add(int l , int r , int val , int s = 0 , int e = maxn , int v = 1)
{
	if(l <= s && e <= r)
	{
		x[v].pb(val);
		return;
	}
	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;
	
	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);
}

void dfs(int s = 0 , int e = maxn , int v = 1 , int h = 0)
{
	for(auto tmp : x[v])
		for(int j = maxk - 1; j >= w[tmp]; j--)
			dp[h][j] = max(dp[h][j] , dp[h][j - w[tmp]] + a[tmp]);

	if(e - s < 2)
	{
		if(is[s])
		{
			ll res = 0 , mx = 0 , pw = 1;
			
			for(int j = 1; j <= k; j++)
			{
				mx = max(mx , dp[h][j]);
				res += mx * pw % mod;
				res %= mod;

				pw *= p;
				pw %= mod;
			}

			cout << res << endl;
		}
		return;
	}

	int m = (s + e) / 2;
	
	for(int j = 0; j < maxk; j++)
		dp[h + 1][j] = dp[h][j];
	dfs(s , m , 2 * v , h + 1);

	for(int j = 0; j < maxk; j++)
		dp[h + 1][j] = dp[h][j];
	dfs(m , e , 2 * v + 1 , h + 1);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i] >> w[i];

		st[i] = 0 , ft[i] = maxn;
	}
	
	int id = n;

	int q;
	cin >> q;

	for(int i = 0; i < q; i++)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			cin >> a[id] >> w[id];

			st[id] = i , ft[id] = maxn;
			id++;
		}

		else if(type == 2)
		{
			int x;
			cin >> x;
			x--;

			ft[x] = i;
		}

		else
			is[i] = 1;
	}

	for(int i = 0; i < id; i++)
		add(st[i] , ft[i] , i);

	dfs();

}