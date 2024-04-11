#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;
const int maxm = 1e6 + 20;

unordered_map<char , int> mp[maxm];

int now = 1 , h[maxm] , t[maxm];

void add(string s)
{
	int pos = 0;
	for(int i = 0; i < (int)s.size(); i++)
	{
		if(!mp[pos][s[i]])
			mp[pos][s[i]] = now++;
		h[mp[pos][s[i]]] = h[pos] + 1;
		pos = mp[pos][s[i]];
	}
	t[pos]++;
}

vector<ll> dfs(int pos)
{
	vector<ll> ans;

	for(int i = 0; i <= t[pos]; i++)
		ans.pb(1LL * h[pos] * i * (i - 1) / 2);

	for(auto x : mp[pos])
	{
		vector<ll> b = dfs(x.second) , c((int)ans.size() + (int)b.size() - 1 , 0);
		for(int i = 0; i < (int)ans.size(); i++)
			for(int j = 0; j < (int)b.size(); j++)
				c[i + j] = max(c[i + j] , (ll)ans[i] + b[j] + 1LL * i * j * h[pos]);
		ans.swap(c);
	}
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		add(s);
	}

	cout << dfs(0)[k] << endl;
}