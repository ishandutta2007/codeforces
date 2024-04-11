#include<bits/stdc++.h>
 
using namespace std;
int n, m, k;
vector <int> tree;
vector <int> upd;
vector <vector <int> > A;
void push(int v, int l, int r)
{
	if(l == r)
	{
		return;
	}
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	tree[v * 2] += upd[v];
	tree[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void update(int v, int l, int r, int ind, int val)
{
	push(v, l, r);
	if(l == r)
	{
		tree[v] = val;
	}
	else if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind, val);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
}
void update1(int v, int l, int r, int al, int ar, int val)
{
	push(v, l, r);
	if(l >= al && r <= ar)
	{
		tree[v] += val;
		upd[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		update1(v * 2, l, (r + l) / 2,  al, ar, val);
		update1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	push(v, l, r);
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		return max(ans(v * 2, l, (r + l) / 2, al, ar), ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	else
	{
		return 0;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	A.resize(n, vector <int> (m));
	vector <vector <int> > pref(n, vector <int> (m + 1));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
		for(int j = 0; j < m; j++)
		{
			pref[i][j + 1] = pref[i][j] + A[i][j];
		}
	}
	tree.resize(4 * m);
	upd.resize(4 * m);
	vector <vector <int> > dp(n, vector <int> (m));
	for(int  i = 0; i < m; i++)
	{
		dp[0][i] = pref[0][min(i + k, m)] - pref[0][i];
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < 4 * m; j++)
		{
			upd[j] = 0;
			tree[j] = 0;
		}
		for(int j = 0; j < m; j++)
		{
			update(1, 0, m - 1, j, dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], ans(1, 0, m - 1, 0, j) + pref[i][min(j + k, m)] - pref[i][j]);
			update1(1, 0, m - 1, max(0, j - k + 1), j, A[i][j]);
		}
		for(int j = 0; j < 4 * m; j++)
		{
			upd[j] = 0;
			tree[j] = 0;
		}
		for(int j = m - 1; j >= 0; j--)
		{
			update(1, 0, m - 1, j, dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], ans(1, 0, m - 1, j, m - 1) + pref[i][min(j + k, m)] - pref[i][j]);
			if(j <= m - k)
			{
				update1(1, 0, m - 1, j, min(m - 1, j + k - 1), A[i][j + k - 1]);
			}
		}
	}
	int res = 0;
	for(int i = 0; i < m; i++)
	{
		res = max(res, dp[n - 1][i]);
	}
	cout << res;
	return 0;
}