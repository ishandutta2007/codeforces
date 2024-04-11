#include <bits/stdc++.h>
using namespace std;
struct Node 
{
	int h, l, r, id;
	Node(int h, int l, int r, int id) : h(h), l(l), r(r), id(id) {}
};
bool operator < (const Node &a, const Node &b) 
{
	if (a.h != b.h) return a.h < b.h;
	return a.id > b.id;
}
const int N = 1e5 + 5, MOD = 1e9 + 7;
set<int> tree[N * 4];
vector<Node> all;
unordered_map<int, int> toid;
int ans[N], s[N];
void build(int x, int l, int r) 
{
	tree[x].insert(0);
	if (l < r) 
	{
		int mid = (l + r) / 2;
		build(x + x, l, mid);
		build(x + x + 1, mid + 1, r);
	}
}
void insert(int x, int l, int r, int ql, int qr, int c) 
{
	if (r < ql || l > qr) return;
	if (l >= ql && r <= qr) 
	{
		tree[x].insert(c);
		return;
	}
	int mid = (l + r) / 2;
	insert(x + x, l, mid, ql, qr, c);
	insert(x + x + 1, mid + 1, r, ql, qr, c);
}
void erase(int x, int l, int r, int ql, int qr, int c) 
{
	if (r < ql || l > qr) return;
	if (l >= ql && r <= qr) 
	{
		tree[x].erase(c);
		return;
	}
	int mid = (l + r) / 2;
	erase(x + x, l, mid, ql, qr, c);
	erase(x + x + 1, mid + 1, r, ql, qr, c);
}
int query(int x, int l, int r, int q) 
{
	if (l > q || r < q) return 0;
	if (l == r) return * -- tree[x].end();
	int mid = (l + r) / 2;
	return max(* -- tree[x].end(), max(query(x + x, l, mid, q), query(x + x + 1, mid + 1, r, q)));
}
int main() 
{
	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);
	toid[0] = 0; 
	ans[0] = 1;
	for (int i = 1; i <= n; i ++) 
	{
		int u, l, r, ss;
		scanf("%d%d%d%d", &u, &l, &r, &ss);
		all.push_back(Node(u, l, r, i));
		if (u + ss <= h) all.push_back(Node(u + ss, l, r, -i));
		toid[u] = i;
		s[i] = ss;
	}
	sort(all.begin(), all.end());
	build(1, 1, w);
	for (auto e : all) 
		if (e.id > 0) 
		{
			if (e.r == w) ans[e.id] = (2 * ans[toid[query(1, 1, w, e.l - 1)]]) % MOD;
			else if (e.l == 1) ans[e.id] = (2 * ans[toid[query(1, 1, w, e.r + 1)]]) % MOD;
			else ans[e.id] = (ans[toid[query(1, 1, w, e.r + 1)]] + ans[toid[query(1, 1, w, e.l - 1)]]) % MOD;
			insert(1, 1, w, e.l, e.r, e.h);
		}
		else erase(1, 1, w, e.l, e.r, e.h - s[-e.id]);
	int Ans = 0;
	for (int i = 1; i <= w; i ++) (Ans += ans[toid[query(1, 1, w, i)]]) %= MOD;
	cout << Ans << endl;
	return 0;
}