#include<bits/stdc++.h>
using namespace std;
vector <int> tree1, tree2;
void update1(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		tree1[v] = min(tree1[v], val);
	}
	else if(l <= ar && r >= al)
	{
		update1(v * 2, l, (r + l) / 2, al, ar, val);
		update1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
void update2(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		tree2[v] = max(tree2[v], val);
	}
	else if(l <= ar && r >= al)
	{
		update2(v * 2, l, (r + l) / 2, al, ar, val);
		update2(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
int ans1(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return tree1[v];
	}
	else if(ind <= (r + l) / 2)
	{
		return min(tree1[v], ans1(v * 2, l, (r + l) / 2, ind));
	}
	else
	{
		return min(tree1[v], ans1(v * 2 + 1, (r + l) / 2 + 1, r, ind));
	}
}
int ans2(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return tree2[v];
	}
	else if(ind <= (r + l) / 2)
	{
		return max(tree2[v], ans2(v * 2, l, (r + l) / 2, ind));
	}
	else
	{
		return max(tree2[v], ans2(v * 2 + 1, (r + l) / 2 + 1, r, ind));
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> v(n);
	vector <int> c(n);
	tree1.resize(4 * n, 1e9);
	tree2.resize(4 * n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	vector <int> val(n);
	int j = n - 1;
	for(int i = n - 1; i >= 0; i--)
	{
		update1(1, 0, n - 1, i, n - 1, c[i]);
		update2(1, 0, n - 1, i, n - 1, v[i]);
		while(j > i && ans1(1, 0, n - 1, j) < ans2(1, 0, n - 1, j) * 100)
		{
			j--;
		}
		val[i] = min(100 * ans2(1, 0, n - 1, j), ans1(1, 0, n - 1, j));
		if(j != n - 1)
		{
			val[i] = max(val[i], min(100 * ans2(1, 0, n - 1, j + 1), ans1(1, 0, n - 1, j + 1)));
		}
		if(j != i)
		{
			val[i] = max(val[i], min(100 * ans2(1, 0, n - 1, j - 1), ans1(1, 0, n - 1, j - 1)));
		}
	}
	sort(val.begin(), val.end());
	vector <long double> prod(n + 1);
	for(int i = n - k + 1; i >= 1; --i)
	{
		if(i == n - k + 1)
		{
			prod[i] = 1;
		}
		else
		{
			prod[i] = prod[i + 1] * i / (i + k);
		}
	}
	long double ans = 0;
	j = 0;
	for(int i = k - 1; i < n; i++)
	{
		long long h = 1LL * val[n - i - 1] * k;
		long double p = h * 1.0 / (i + 1) * prod[i + 1 - k + 1];
		ans += p;
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}