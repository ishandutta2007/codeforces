#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector <pair <int, int> > adds[200001];
vector <pair <int, int> > tree[400000];
void update(int v, int l, int r, int al, int ar, int a, int val)
{
	if(l >= al && r <= ar)
	{
		if(tree[v].size() != 0)
		{
			val = 1LL * val * tree[v].back().second % mod;
		}
		tree[v].push_back({a, val});
	}
	else if(l <= ar && r >= al)
	{
		update(v * 2, l, (r + l) / 2, al, ar, a, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, a, val);
	}
}
int ans(int v, int l, int r, int al, int ar){
	
		int ind = lower_bound(tree[v].begin(), tree[v].end(), make_pair(ar + 1, 0)) - tree[v].begin();
		ind--;
		int res = ind >= 0? tree[v][ind].second : 1;
		if(l < r)
		{
			if(al <= (r + l) /2)
			{
				res= 1LL * res * ans(v * 2, l, (r + l) / 2, al, ar) % mod;
			}
			else
			{
				res = 1LL * res * ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar) % mod;
			}
		}
	return res;
}
signed main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> p(2e5 + 1, -1);
	for(int i = 2; i <= 2e5; i++)
	{
		if(p[i] == -1)
		{
			for(int j = i; j <= 2e5; j += i)
			{
				p[j] = i;
			}
		}
	}
	set <pair <int, int> > s[200001];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		while(a[i] > 1)
		{
			int p1 = p[a[i]];
			int c = 0;
			while(a[i] % p1 == 0)
			{
				c++;
				a[i] = a[i] / p1;
			}
			s[p1].insert({i, c});
		}
	}
	for(int i = 2; i <= 2e5; i++)
	{
		set <pair <int, int> > :: iterator it;
		for(int j = 1; s[i].size() > 0; j++)
		{
			int cur = 0;
			for(it = s[i].begin(); it != s[i].end();)
			{
				adds[it -> first].push_back({cur, i});
				cur = it -> first + 1;
				if(j == it -> second)
				{
					s[i].erase(it++);
				}
				else
				{
					it++;
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < adds[i].size(); j++)
		{
			update(1, 0, n - 1, adds[i][j].first, i, i, adds[i][j].second);
		}
	}
	int m;
	cin >> m;
	int last = 0;
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		l = (l + last) % n;
		r = (r + last) % n;
		if(l > r)
		{
			swap(l, r);
		}
		cout << (last = ans(1, 0, n - 1, l, r)) << "\n";
	}
    return 0;
}