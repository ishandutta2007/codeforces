#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> tree;
vector <int> treeleft, treeright;
vector <int> tree1, tree2;
vector <int> a, w;
const int const1 = 1e9 + 7;
void update(int v, int l, int r, int ind, int val)
{
	if(l == r)
	{
		tree[v] = val;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind, val);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
	}
	int len1 = (r + l) / 2 + 1 - l;
	int len2 = r - (r + l) / 2; 
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
	treeleft[v] = treeleft[v * 2] + treeleft[v * 2 + 1] + (tree[v * 2 + 1] % const1) * (a[(r + l) / 2 + 1] - a[l] - len1);
	treeright[v] = treeright[v * 2 + 1] + treeright[v * 2] + (tree[v * 2] % const1) * (a[r] - len2 - a[(r + l) / 2]);
	treeleft[v] %= const1;
	treeright[v] %= const1;
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		tree1[v] = ans(v * 2, l, (r + l) / 2, al, ar);
		tree2[v] = ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		return tree1[v] + tree2[v];
	}
	else
	{
		return 0;
	}
}
int ans1(int v, int l, int r, int al, int ar, int sum)
{
	if(l >= al && r <= ar)
	{
		if(l == r)
		{
			return l;
		}
		if(tree[v * 2] * 2 > sum)
		{
			return ans1(v * 2, l, (r + l) / 2, al, ar, sum);
		}
		return ans1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, sum - 2 * tree[v * 2]);
	}
	if(tree1[v] * 2 > sum)
	{
		return ans1(v * 2, l, (r + l) / 2, al, ar, sum);
	}
	return ans1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, sum - 2 * tree1[v]);
}
int ans2(int v, int l, int r, int al, int ar, int ind)
{
	if(al > ar)
	{
		return 0;
	}
	if(l >= al && r <= ar)
	{
		int sum = 0;
		if(ind == a[ar])
		{
			sum += treeright[v];
			sum += (tree[v] % const1) * (ind - (ar - r) - a[r]) % const1;
		}
		if(ind <= a[al])
		{
			sum += treeleft[v];
			sum += (tree[v] % const1) * (a[l] - ind - (l - al)) % const1;
		}
		if(sum >= const1){
			sum -= const1;
		}
		return sum;
	}
	else if(l <= ar && r >= al)
	{
		int sum = ans2(v * 2, l, (r + l) / 2, al, ar, ind) + ans2(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, ind);
		if(sum >= const1)
		{
			sum -= const1;
		}
		return sum;
	}
	else
	{
		return 0;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	tree1.resize(4 * n, 0);
	tree2.resize(4 * n, 0);
	treeleft.resize(4 * n, 0);
	treeright.resize(4 * n, 0);
	tree.resize(4 * n);
	a.resize(n), w.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> w[i];
		update(1, 0, n - 1, i, w[i]);
	}
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		if(x < 0)
		{
			int id, val;
			id = -x;
			val = y;
			id--;
			update(1, 0, n - 1, id, val);
		}
		else
		{
			int l, r;
			l = x;
			r = y;
			l--;
			r--;
			int sum = ans(1, 0, n - 1, l, r);
			int ind = ans1(1, 0, n - 1, l, r, sum);
			int t = ans2(1, 0, n - 1, l, ind, a[ind]) + ans2(1, 0, n - 1, ind + 1, r, a[ind] + 1);
			if(t >= const1)
			{
				t -= const1;
			}
			cout << t << "\n";
		}
	}
	return 0;
}