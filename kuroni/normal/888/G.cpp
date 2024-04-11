#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct TNode
{
	int cnt = 0;
	TNode *bit[2] = {nullptr};
	vector<int> pos;
} *root = new TNode;
vector<int> adj[200005], com;
vector<pair<int, int>> st;
int n, a[200005], i, rt[200005], cur;
long long ans = 0;
bool vis[200005], chk[200005];

void DFS(int u)
{
	vis[u] = true;
	com.push_back(u);
	for (int v : adj[u])
		if (!vis[v])
			DFS(v);
}

int trace(int i)
{
	return rt[i] < 0 ? i : rt[i] = trace(rt[i]);
}

bool unity(int a, int b)
{
	if ((a = trace(a)) == (b = trace(b)))
		return false;
	if (rt[a] > rt[b])
		swap(a, b);
	rt[a] += rt[b];
	rt[b] = a;
	return true;
}

void add(int x)
{
	TNode *cur = root;
	for (int i = 29; i >= 0; i--)
	{
		if (cur->bit[a[x] >> i & 1] == nullptr)
			cur->bit[a[x] >> i & 1] = new TNode;
		cur=cur->bit[a[x] >> i & 1];
		cur->cnt++;
	}
	cur->pos.push_back(x);
	chk[x] = true;
}

void del(int x)
{
	TNode *cur = root;
	for (int i = 29; i >= 0; i--)
	{
		cur = cur->bit[a[x] >> i & 1];
		cur->cnt--;
	}
	int v = cur->pos.back();
	if (vis[v] ^ chk[v])
		cur->pos.pop_back();
}

int que(int x)
{
	TNode *cur = root;
	for (int i = 29; i >= 0; i--)
		cur = (cur->bit[a[x] >> i & 1] == nullptr || cur->bit[a[x] >> i & 1]->cnt == 0) ? cur->bit[a[x] >> i & 1 ^ 1] : cur->bit[a[x] >> i & 1];
	return cur->pos.back();
}

void solve(int u)
{
	int x = 0, y = 0, z;
	DFS(u);
	for (int i : com)
		del(i);
	for (int i : com)
	{
		z = que(i);
		if (x == 0 || (a[x] ^ a[y]) > (a[z] ^ a[i]))
		{
			x = i;
			y = z;
		}
	}
	if (unity(x, y))
	{
		cur--;
		ans += (a[x] ^ a[y]);
		st.push_back(make_pair(x, y));
	}
	while (!com.empty())
	{
		add(com.back());
		com.pop_back();
	}
}

int main()
{
	scanf("%d", &n);
	cur = n;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		rt[i] = -1;
	}
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	for (i = 1; i <= n; i++)
	    add(i);
	cur = n;
	while (cur != 1)
	{
		memset(vis, 0, sizeof(vis));
		memset(chk, 0, sizeof(chk));
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				solve(i);
		while (!st.empty())
		{
			adj[st.back().first].push_back(st.back().second);
			adj[st.back().second].push_back(st.back().first);
			st.pop_back();
		}
	}
	printf("%I64d", ans);
}