#include<bits/stdc++.h>
using namespace std;
const int const1 = 1e9 + 7;
vector <int> tree;
vector <int> upd;
void push(int v, int l, int r)
{
	tree[v * 2] += upd[v];
	tree[v * 2 + 1] += upd[v];
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		tree[v] += val;
		upd[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
}
pair <int, int> ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		if(l == r)
		{
			return make_pair(l, tree[v]);
		}
		push(v, l, r);
		if(tree[v * 2] <= 0)
		{
			return ans(v * 2, l, (r + l) / 2, al, ar);
		}
		return ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		pair <int, int> t1 = ans(v * 2, l, (r + l) / 2, al, ar);
		pair <int, int> t2 = ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		if(t1.second <= 0)
		{
			return t1;
		}
		return t2;
	}
	else
	{
		return {-1, 1e9};
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, t;
	cin >> s >> t;
	int n= s.size();
	int m = t.size();
	vector <vector <int> > dp(n + 1, vector <int> (m + 1, 1e9));
	dp[0][0] = 0;
	vector <int> go_to(n, 0);
	tree.resize(4 * n);
	upd.resize(4 * n);
	for(int i = n - 1; i >= 0; i--)
	{
		if(s[i] == '.')
		{
			update(1, 0, n - 1, i, n - 1, -1);
		}
		else
		{
			update(1, 0, n - 1, i, n - 1, 1);
		}
		pair <int, int> a = ans(1, 0, n - 1, i, n - 1);
		if(a.second == 0){
			go_to[i] = a.first - i + 1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(s[i] == '.' && j > 0)
			{
				dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
			}
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			if(j < m && s[i] == t[j])
			{
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
			}
			if(go_to[i] != 0)
			{
				dp[i + go_to[i]][j] = min(dp[i + go_to[i]][j], dp[i][j]);
			}
		}
	}
	cout << dp[n][m];
    return 0;
}