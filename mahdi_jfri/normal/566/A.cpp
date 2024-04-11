#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

typedef pair<pair<ll , ll> , ll> shit;

const int maxn = 2e5 + 20;
const int maxs = 8e5 + 20;
const ll mod[2] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const ll base[2] = {3079 , 737};

set<shit> st[maxs];
set<shit>::iterator it;

ll h[2] , partner[maxn];

string s[maxn];

int main()
{
	int n;
	cin >> n;

	fill(partner , partner + maxn , -1);
	
	for(int i = 0; i < 2 * n; i++)
	{
		cin >> s[i];
		int m = s[i].size();

		h[0] = h[1] = 0;
		st[0].insert({{0 , 0} , i});
		for(int j = 0; j < m; j++)
		{
			for(int k = 0; k < 2; k++)
				h[k] = (h[k] * base[k] + s[i][j]) % mod[k];
			st[j + 1].insert({{h[0] , h[1]} , i});
		}
	}
	ll res = 0;
	for(int i = maxs - 1; i >= 0; i--)
		while(!st[i].empty())
		{
			shit x = *st[i].begin();
			st[i].erase(st[i].begin());
			int k = x.second;
			if(k >= n)
				continue;
			if(partner[k] != -1)
				continue;
			x.second = n;
			bool f = 0;

			while(!f && !st[i].empty())
			{
				it = st[i].lower_bound(x);
				if(it == st[i].end() || (it -> first) != (x.first))
					break;
				if(partner[it -> second] == -1)
					f = 1;
				else
					st[i].erase(it);
			}

			if(f)
			{
				it = st[i].lower_bound(x);
				partner[k] = it -> second;
				partner[it -> second] = k;
				st[i].erase(it);
				res += i;
			}
			
		}
	cout << res << endl;
	for(int i = 0; i < n; i++)
		cout << i + 1 << " " << partner[i] - n + 1 << endl;
}