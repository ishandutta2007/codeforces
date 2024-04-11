
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1000043;
map <char, int> nxt[N];
bool term[N];
char buf[3];
int dp[N];
int dict[N];
int T[N * 4];
int n, k;
int f[N * 4];
void build(int v, int l, int r)
{
	T[v] = 1e9;
	if(l != r - 1)
	{
		int m = (r + l) / 2;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m, r);
	}
}
int getVal(int v)
{
	return T[v] + f[v];
}
void push(int v, int l, int r)
{
	T[v] += f[v];
	if(l != r - 1)
	{
		f[v * 2 + 1] += f[v];
		f[v * 2 + 2] += f[v];
	}
	f[v] = 0;
}
void upd(int v, int l, int r)
{
	if(l != r - 1)
	{
		T[v] = min(getVal(v * 2 + 1), getVal(v * 2 + 2));
	}
}
int get(int v, int l, int r, int L, int R)
{
	if(L >= R)
	{
		return 1e9;
	}
	if(l == L && r == R)
	{
		return getVal(v);
	}
	push(v, l, r);
	int m = (r + l) / 2;
	int ans = min(get(v * 2 + 1, l, m, L, min(R, m)), get(v * 2 + 2, m, r, max(L, m), R));
	upd(v, l, r);
	return ans;
}
void add(int v, int l, int r, int L, int R, int val)
{
	if(L >= R)
	{
		return;
	}
	if(l == L && r == R)
	{
		f[v] += val;
		return;
	}
	push(v, l, r);
	int m = (r + l) / 2;
	add(v * 2 + 1, l, m, L, min(R, m), val);
	add(v * 2 + 2, m, r, max(L, m), R, val);
	upd(v, l, r);
}
void setVal(int v, int l, int r, int pos, int val)
{
	if(l == r - 1)
	{
		f[v] = 0;
		T[v] = val;
		return;
	}
	push(v, l, r);
	int m = (r + l) / 2;
	if(pos < m)
	{
		setVal(v * 2 + 1, l, m, pos, val);
	}
	else
	{
		setVal(v * 2 + 2, m, r, pos, val);
	}
	upd(v, l, r);
}
void dfs(int v, int d, int last)
{
	dp[v] = last + 1;
	if(term[v])
	{
		dp[v] = min(dp[v], get(0, 0, n + 1, 0, d));
	}
	setVal(0, 0, n + 1, d, dp[v] + 1);
	if(term[v])
	{
		add(0, 0, n + 1, 0, d + 1, 1);
	}
	map <char, int> :: iterator it;
	for(it = nxt[v].begin(); it != nxt[v].end(); it++)
	{
		dfs(it -> second, d + 1, dp[v]);
	}
	setVal(0, 0, n + 1, d, 1e9);
}
signed main() {
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		cin >> buf;
		char c = buf[0];
		nxt[p][c] = i + 1;
	}
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> dict[i];
		term[dict[i]] = true;
 	}
 	build(0, 0, n + 1);
 	dfs(0, 0, -1);
 	for(int i = 0; i < k; i++)
 	{
 		cout << dp[dict[i]] << " ";
 	}
	return 0;
}