#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % mod;
	}
	else
	{
		int t = power(a, b - 1);
		return t * a % mod;
	}
}
vector <int> fact, fact1;
int cnk(int n, int k)
{
	if(n < 0 || k < 0 || n < k)
	{
		return 0;
	}
	return fact[n] * fact1[n - k] % mod * fact1[k] % mod;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	fact.resize(n + 1);
	fact1.resize(n + 1);
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		fact[i] = fact[i - 1] * i % mod;
	}
	fact1[n] = power(fact[n], mod - 2);
	for(int i = n - 1; i >= 0; i--)
	{
		fact1[i] = fact1[i + 1] * (i + 1) % mod;
	}
	vector <pair <int, int> > mass(n);
	vector <int> cnt(n + 2);
	for(int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		cnt[l]++;
		cnt[r + 1]--;
		mass[i] = {l, r};
	}
	for(int i = 1; i <= n; i++)
	{
		cnt[i] += cnt[i - 1];
	}
	vector <int> uniq;
	vector <int> masks(n);
	vector <vector <int> > g(n);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		uniq.push_back(a);
		uniq.push_back(b);
		masks[a] |= (1 << i);
		masks[b] |= (1 << i);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	sort(uniq.begin(), uniq.end());
	int k = unique(uniq.begin(), uniq.end()) - uniq.begin();
	vector <vector <int> > pref(k + 1, vector <int> (n + 1));
	for(int i = 0; i <= k; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j != 0)
			{
				pref[i][j] += pref[i][j - 1];
			}
			pref[i][j] += cnk(cnt[j] - i, j - i);
			if(pref[i][j] >= mod)
			{
				pref[i][j] -= mod;
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < (1 << m); i++)
	{
		int L = 1;
		int R = n;
		int c = 0;
		int c1 = 0;
		for(int j = 0; j < m; j++)
		{
			if((1 << j) & i)
			{
				c1++;
			}
		}
		for(int j = 0; j < k; j++)
		{
			if((masks[uniq[j]] & i) != 0)
			{
				c++;
				L = max(L, mass[uniq[j]].first);
				R = min(R, mass[uniq[j]].second);
			}
		}
		if(L <= R)
		{
			if(c1 % 2 == 0)
			{
				sum += pref[c][R];
				if(L != 0)
				{
					sum -= pref[c][L - 1];
				}
			}
			else
			{
				sum -= pref[c][R];
				if(L != 0)
				{
					sum += pref[c][L - 1];
				}
			}
			if(sum >= mod)
			{
				sum -= mod;
			}
			if(sum < 0)
			{
				sum += mod;
			}
		}
	}
	cout << sum;
	return 0;
}