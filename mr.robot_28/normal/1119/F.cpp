#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <pair <int, int> > > g;
vector <set <pair <int, int> > > s;
vector <int> p;
vector <vector <int> > dp;
vector <bool> used1;
vector <vector <pair <int, int> > > g1;
struct node{
	node* left;
	node* right;
	int val, _sz, priority;
	int sum;
	node(int val, int priority):
		sum(val),
		val(val),
		_sz(1),
		left(NULL),
		right(NULL),
		priority(priority){};
};
void upd(node* &v)
{
	v -> sum = v -> val;
	v -> _sz = 1;
	if(!v -> left)
	{
		
	}
	else
	{
		v -> sum += v -> left -> sum;
		v -> _sz += v -> left -> _sz;
	}
	if(!v -> right)
	{
		
	}
	else
	{
		v -> sum += v -> right -> sum;
		v -> _sz += v -> right -> _sz;
	}
}
void split(node* v, node* &l, node* &r, int val)
{
	if(!v)
	{
		l = r = NULL;
		return;
	}
	if(v -> val < val)
	{
		split(v -> right, v -> right, r, val);
		l = v;
		upd(l);
	}
	else
	{
		split(v -> left, l, v -> left, val);
		r = v;
		upd(r);
	}
}
void split1(node* v, node* &l, node* &r, int val)
{
	if(!v)
	{
		l = r = NULL;
		return;
	}
	int leftsz = 1;
	if(!v -> left)
	{
		
	}
	else
	{
		leftsz += v -> left -> _sz;
	}
	if(leftsz <= val)
	{
		split1(v -> right, v -> right, r, val - leftsz);
		l = v;
		upd(l);
	}
	else
	{
		split1(v -> left, l, v -> left, val);
		r = v;
		upd(r);
	}
}
node* merge(node* l, node* r)
{
	if(!l)
	{
		return r;
	}
	else if(!r)
	{
		return l;
	}
	if(l -> priority < r -> priority)
	{
		l -> right = merge(l -> right, r);
		upd(l);
		return l;
	}
	else
	{
		r -> left = merge(l, r -> left);
		upd(r);
		return r;
	}
}
void erase(node* &v, int val)
{
	node* L;
	node* R;
	split(v, L, R, val);
	node* L1;
	node* R1;
	split1(R, L1, R1, 1);
	v = merge(L, R1);
}
void add(node* &root, int val)
{
	node* v = new node(val, rand());
	node* L;
	node* R;
	split(root, L, R, val);
	L = merge(L, v);
	root = merge(L, R);
}
int query(node *v, int cnt)
{
	if(cnt <= 0)
	{
		return 0;
	}
	if(!v || v -> _sz < cnt)
	{
		return 1e12;
	}
	node* L;
	node* R;
	split1(v, L, R, cnt);
	int sum =0;
	if(!L)
	{
	}
	else
	{
		sum = L -> sum;
	}
	v = merge(L, R);
	return sum;
}
vector <node*> trees;
int up;
void dfs(int v, int p = -1)
{
	used1[v] = 1;
	vector <int> mass;
	int sum = 0;
	for(int j = 0; j < g1[v].size(); j++)
	{
		int to = g1[v][j].first;
		int w = g1[v][j].second;
		if(to == p)
		{
			continue;
		}
		dfs(to, v);
		dp[to][1] += w;
		dp[to][1] = min(dp[to][1], 1000000000000);
		mass.push_back(dp[to][1] - dp[to][0]);
		sum += dp[to][0];
	}
	if(mass.size() == 0)
	{
		
	dp[v][0] = min(dp[v][0], sum + query(trees[v], g[v].size() - up));
	dp[v][1] = min(dp[v][1], sum + query(trees[v], g[v].size() - up - 1));
//	cout << v << " " << dp[v][0] << " " << dp[v][1] << "\n";
	return;
	}
	sort(mass.begin(), mass.end());
	dp[v][0] = min(dp[v][0], sum + query(trees[v], g[v].size() - up));
	dp[v][1] = min(dp[v][1], sum + query(trees[v], g[v].size() - up - 1));
//	cout << v << " " << dp[v][0] << " " << dp[v][1] << "\n";
	for(int i = 0; i < mass.size(); i++)
	{
		sum += mass[i];
//		cout << sum << "\n";
		int cnt = g[v].size() - up - (i + 1);
		int cnt1 = g[v].size() - up - (i + 1) - 1;
//		cout << cnt << " " << cnt1 << "\n";
		cnt = max(cnt, 0LL);
		if(cnt >= 0)
		{
			dp[v][0] = min(dp[v][0], sum + query(trees[v], cnt));
		}
		cnt1 = max(cnt1, 0LL);
		if(cnt1 >= 0)
		{
			dp[v][1] = min(dp[v][1], sum + query(trees[v], cnt1));
		}
	}
//	cout << v << " " << dp[v][0] << " " << dp[v][1] << "\n";
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	g1.resize(n);
	trees.resize(n);
	for(int i = 0; i < n; i++)
	{
		trees[i] = NULL;
	}
	used1.resize(n);
	dp.resize(n, vector <int> (2, 1e12));
	g.resize(n);
	p.resize(n, -1);
	for(int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	vector <vector <int> > vec(n);
	for(int i = 0; i < n; i++)
	{
		vec[g[i].size() - 1].push_back(i);
	}
	vector <int> mass;
	vector <bool> used(n);
	vector <int> ans(n);
	for(up = n - 1; up >= 0; up--)
	{
		for(int j = 0; j < vec[up].size(); j++)
		{
			int v = vec[up][j];
			used[v] = 1;
			for(int k = 0; k < g[v].size(); k++)
			{
				int a = v;
				int b = g[v][k].first;
				int c = g[v][k].second;
				if(used[b])
				{
					erase(trees[b], c);
					g1[a].push_back({b, c});
					g1[b].push_back({a, c});
				}
				else
				{
					add(trees[a], c);
				}
			}
			mass.push_back(v);
		}
//		cout << up << "A\n";
		int sum = 0;
		for(int j = 0; j < mass.size(); j++)
		{
			if(!used1[mass[j]])
			{
				dfs(mass[j]);
				sum += dp[mass[j]][0];
			}
		}
		for(int j = 0; j < mass.size(); j++)
		{
			int v = mass[j];
			used1[v] = 0;
			dp[v][0] = dp[v][1] = 1e12;
		}
		ans[up] = sum;
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}