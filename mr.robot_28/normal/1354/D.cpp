#include <bits/stdc++.h>
 
using namespace std;
int tree[4000000];
void update(int v, int l, int r, int ind, int up)
{
	if(l == r)
	{
		tree[v] += up;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind, up);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind, up);
	}
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}
int ans(int v, int l, int r, int k)
{
	if(l == r)
	{
		return l;
	}
	if(tree[v * 2] >= k)
	{
		return ans(v * 2, l ,(r + l) / 2, k);
	}
	else
	{
		return ans(v * 2 + 1, (r + l) / 2 + 1, r, k - tree[v * 2]);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector <int> cnt(n);
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		cnt[a - 1]++;
		update(1, 0, n - 1, a - 1, 1);
	}
	for(int i = 0; i < q; i++)
	{
		int a;
		cin >> a;
		if(a < 0)
		{
			int d = ans(1, 0, n - 1, -a);
			cnt[d]--;
			update(1, 0, n - 1, d, -1);
		}
		else
		{
			cnt[a -1]++;
			update(1, 0, n - 1, a - 1, 1);
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(cnt[i] != 0)
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << 0;
    return 0;
}