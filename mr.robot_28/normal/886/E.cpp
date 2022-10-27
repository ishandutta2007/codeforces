#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
vector <ll> tree, upd;
void build(int v, int l, int r)
{
	upd[v] = 1;
	tree[v] = r - l + 1;
	if(l != r)
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
	}
}
void push(int v, int l, int r)
{
	if(upd[v] == 1)
	{
		return;
	}
	tree[v] = tree[v] * upd[v] % mod;
	if(l != r)
	{
		upd[v * 2] = upd[v * 2] * upd[v] % mod;
		upd[v * 2 + 1] = upd[v * 2 + 1] * upd[v] % mod;
	}
	upd[v] = 1;
}
int mult(int v, int l, int r, int al, int ar, ll val)
{
	push(v, l, r);
	if(l >= al && r <= ar)
	{
		upd[v] = val;
		push(v, l, r);
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		return tree[v] = (mult(v * 2, l, (r + l) / 2, al, ar, val) + mult(v *2  + 1, (r + l) / 2 + 1, r, al, ar, val)) % mod;
	}
	return tree[v];
}
int sum(int v, int l, int r, int al, int ar)
{
	push(v, l, r);
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		return (sum(v * 2, l, (r + l) / 2, al, ar) + sum(v * 2 + 1, (r + l) / 2 + 1, r, al, ar)) % mod;
	}
	return 0;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	tree.resize(4 * n);
	upd.resize(4 * n);
	build(1, 0, n - 1);
	ll fact = 1;
	for(int i = 1; i < n; i++)
	{
		fact *= 1LL * (i + 1);
		fact %= mod;
		int val = sum(1, 0, n - 1, max(0, i - k), i- 1);
		mult(1, 0, n - 1, 0, i - 1, i);
		mult(1, 0, n - 1, i, i, val);
	}
	cout << (fact - sum(1, 0, n - 1, 0, n - 1) + mod) % mod;
	return 0;
}