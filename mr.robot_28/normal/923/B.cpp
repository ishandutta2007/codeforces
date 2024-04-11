#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <int> tree, upd;
void push(int v)
{
	tree[v * 2] += upd[v];
	tree[v * 2 + 1] += upd[v];
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int up)
{
	if(l >= al && r <= ar)
	{
		tree[v] += up;
		upd[v] += up;
	}
	else if(l <= ar && r >= al)
	{
		push(v);
		update(v * 2, l, (r + l) / 2, al, ar, up);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, up);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
}
int ans = 0;
int cnt = 0;
void go_to(int v, int l, int r, int al, int ar, int add)
{
	if(l >= al && r <= ar){
		if(tree[v] < add)
		{
			if(l == r)
			{
				ans += tree[v];
				tree[v] = 1e18;
				cnt++;
			}
			else
			{
				push(v);
				go_to(v * 2, l, (r + l) / 2, al, ar, add);
				go_to(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, add);
				tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
			}
		}
	}
	else if(l <= ar && r >= al)
	{
		push(v);
		go_to(v * 2, l, (r + l) / 2, al, ar, add);
		go_to(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, add);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	tree.resize(4 * n, 0);
	upd.resize(4 * n, 0);
	vector <int> a(n), t(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> t[i];
		update(1, 0, n - 1, i, i, a[i]);
		go_to(1, 0, n - 1, 0, i, t[i]);
		ans += (i + 1 - cnt) * t[i];
		cout << ans << " ";
		update(1, 0, n - 1, 0, i, -t[i]);
		ans = 0;
	}
    return 0;
}