#include <bits/stdc++.h>
                  
using namespace std;
vector <vector <vector <int> > > tree;
vector <int> a;
const int const1 = 998244353;
void build(int v, int l, int r)
{
	if(l == r)
	{
		tree[v][0][1] = tree[v][1][0] = 1;
		tree[v][1][1] = a[l] + 1;
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				tree[v][i][j] += 1LL * tree[v * 2][i][1] * tree[v * 2 + 1][1][j] % const1;
				if(tree[v][i][j] >= const1)
				{
					tree[v][i][j] -= const1;
				}
				if(a[(r + l) / 2] == 1)
				{
					int sum = a[(l + r) / 2] * 10 + a[(r + l) / 2 + 1];
					sum = 9 - (sum - 9) + 1;
					tree[v][i][j] += 1LL * tree[v * 2][i][0] * tree[v * 2 + 1][0][j] % const1 * sum % const1;
					if(tree[v][i][j] >= const1)
					{
						tree[v][i][j] -= const1;
					}
				}
			}
		}
	}
}
void update(int v, int l, int r, int ind)
{
	if(l == r)
	{
		tree[v][0][1] = tree[v][1][0] = 1;
		tree[v][1][1] = a[l] + 1;	
		return;
	}
	else if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			tree[v][i][j] = 1LL * tree[v * 2][i][1] * tree[v * 2 + 1][1][j] % const1;
			if(tree[v][i][j] >= const1)
			{
				tree[v][i][j] -= const1;
			}
			if(a[(r + l) / 2] == 1)
			{
				int sum = a[(l + r) / 2] * 10 + a[(r + l) / 2 + 1];
				sum = 9 - (sum - 9) + 1;
				tree[v][i][j] += 1LL * tree[v * 2][i][0] * tree[v * 2 + 1][0][j] % const1 * sum % const1;
				if(tree[v][i][j] >= const1)
				{
					tree[v][i][j] -= const1;
				}
			}
		}
	}
}
signed main(){
	int n, m;
	cin >> n >> m;
	tree.resize(4 * n, vector <vector <int> > (2, vector <int> (2)));
	a.resize(n);
	string s;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		a[i] = s[i] - '0';
	}
	build(1, 0, n - 1);
	for(int i = 0; i < m; i++)
	{
		int x, d;
		cin >> x >> d;
		x--;
		a[x] = d;
		update(1, 0, n - 1, x);
		cout << tree[1][1][1] << "\n";
	}
	return 0;
}