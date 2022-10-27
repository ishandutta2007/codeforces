#include <bits/stdc++.h>
using namespace std;

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
void update1(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		tree[v]++;
		upd[v]++;
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		update1(v * 2, l, (r + l) / 2, al, ar);
		update1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
}
void update(int v, int l, int r, int ind, int val)
{
	if(l == r)
	{
		tree[v] = min(tree[v], val);
		return;
	}
	push(v, l, r);
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind, val);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
	}
	tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		return min(ans(v * 2, l, (r + l) / 2, al, ar), ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	return 1e9;
}
void find(int v, int l, int r)
{
	tree[v] = 1e9;
	if(l == r)
	{
		return;
	}
	push(v, l, r);
	if(tree[v * 2] < 1e9)
	{
		find(v * 2, l, (r + l) / 2);
	}
	if(tree[v * 2 + 1] < 1e9)
	{
		find(v * 2 + 1, (r + l) / 2 + 1, r);
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	upd.resize(8 * n + 8);
	tree.resize(8 * n + 8, 0);
	vector <int> a(n);
	vector <int> uniq;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] = a[i] - i + n;
		uniq.push_back(a[i]);
	}
	sort(uniq.begin(), uniq.end());
	int m = unique(uniq.begin(), uniq.end()) - uniq.begin();
	vector <bool> used(n);
	for(int i= 0; i < k; i++)
	{
		int a;
		cin >> a;
		a--;
		used[a] = 1;
	}
	int it = 0;
	for(int i = 0; i < n; i++)
	{
		int ind = upper_bound(uniq.begin(), uniq.begin() + m, a[i]) - uniq.begin();
		ind--;
	//	cout << ind << "\n";
	//	cout << a[i] << " ";
		int ns = ans(1, 0, m - 1, 0, ind);
		if(used[i])
		{
			find(1, 0, m - 1);
		}
	//	cout << i << "\n";
		if(ind != 0)
		{
		update1(1, 0, m - 1, 0 , ind - 1);
		}
		if(ind + 1 < m)
		{
		update1(1, 0, m - 1, ind + 1, m - 1);
		}update(1, 0, m - 1, ind, ns);
	}
	if(tree[1] > n)
	{cout << -1;
	return 0;
	}
	cout << tree[1] << "\n";
/*	int t;
	cin >> t;
	while(t--)
	{
		vector <int> vec1, vec2, vec3, vec4;
		int n;
		cin >> n;
		string s;
		cin >> s;
		int sum1 = 0, sum2 = 0;
		for(int i = 0; i < n; i++)
		{
			
		}
		cout << min(sum1,sum2) << "\n";
	}*/
	return 0;
}