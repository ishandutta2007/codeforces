#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int mod[2] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const int base[2] = {737 , 4001};
const int maxs = 27;
const int sq = 320;

int pw[maxn][2] , h[maxn][2];

string m[maxn];
int ans[maxn] , H[2] , adj[maxn][maxs] , id = 1 , has[maxn] , k[maxn];

vector<int> shits[maxn];

inline int get_str(string &s , int k)
{
	int h = 0;

	for(auto ch : s)
		h = (1LL * h * base[k] + ch) % mod[k];

	return h;
}

inline int get(int l , int r , int k)
{
	int ans = (1LL * h[r][k] - 1LL * h[l][k] * pw[r - l][k]) % mod[k];
	ans += mod[k];

	return ans % mod[k];
}

void prepare()
{
	pw[0][0] = pw[0][1] = 1;

	for(int i = 1; i < maxn; i++)
		for(int j = 0; j < 2; j++)
			pw[i][j] = 1LL * pw[i - 1][j] * base[j] % mod[j];
}

void add(int i)
{
	int pos = 0;

	for(auto ch : m[i])
	{
		if(adj[pos][ch - 'a'] == -1)
			adj[pos][ch - 'a'] = id++;

		pos = adj[pos][ch - 'a'];
	}

	has[pos] = i;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	prepare();

	string s;
	cin >> s;
	int n = s.size();

	for(int i = 0; i < n; i++)
		for(int j = 0; j < 2; j++)
			h[i + 1][j] = (1LL * h[i][j] * base[j] + s[i]) % mod[j];

	int q;
	cin >> q;
	
	memset(ans , 63 , sizeof ans);
	memset(adj , -1 , sizeof adj);

	for(int i = 1; i <= q; i++)
	{
		cin >> k[i] >> m[i];

		int t = m[i].size();

		if(t >= sq)
		{
			for(int j = 0; j < 2; j++)
				H[j] = get_str(m[i] , j);

			vector<int> tmp;
			for(int j = 0; j + t <= n; j++)
			{
				bool f = 1;
				for(int x = 0; x < 2; x++)
					if(get(j , j + t , x) != H[x])
						f = 0;

				if(f)
					tmp.pb(j);
			}

			for(int j = k[i] - 1; j < (int)tmp.size(); j++)
				ans[i] = min(ans[i] , tmp[j] - tmp[j - k[i] + 1]);
		}
		else
			add(i);
	}

	for(int i = 0; i < n; i++)
	{
		int pos = 0;

		for(int j = i; j < n && j < i + sq; j++)
		{
			if(adj[pos][s[j] - 'a'] == -1)
				break;

			pos = adj[pos][s[j] - 'a'];
			if(has[pos])
				shits[has[pos]].pb(j);
		}
	}

	for(int i = 1; i <= q; i++)
	{
		int t = m[i].size();

		if(t < sq)
			for(int j = k[i] - 1; j < (int)shits[i].size(); j++)
				ans[i] = min(ans[i] , shits[i][j] - shits[i][j - k[i] + 1]);

		ans[i] += t;

		if(ans[i] > n)
			ans[i] = -1;

		cout << ans[i] << endl;
	}

}