#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#define MN 801000

typedef std::pair<int, int> P;

std::vector<P> v[MN];
std::vector<int> w[MN];
std::map<P, int> mp;

int opt[MN], x[2][MN], y[2][MN]; 
int ans = 0;
int fa[MN], siz[MN];
int nxt[2][MN];
bool lst[2][MN];
int n, m; 

int Find(int x) {return fa[x] == x ? x : Find(fa[x]);}

void modify(int x, int l, int r, int L, int R, P p)
{
	if(L > R) return;
	if(l == L && r == R) {v[x].push_back(p); return;}
	int mid = l + r >> 1;
	if(R <= mid) modify(x << 1, l, mid, L, R, p);
	else if(L > mid) modify(x << 1 | 1, mid + 1, r, L, R, p);
	else modify(x << 1, l, mid, L, mid, p), modify(x << 1 | 1, mid + 1, r, mid + 1, R, p);
}

void query(int k, int l, int r)
{
	for(int i = 0; i < v[k].size(); i++)
	{
		int dx = Find(v[k][i].first);
		int dy = Find(v[k][i].second);
		if(dx != dy)
		{
			if(siz[dx] > siz[dy]) std::swap(dx, dy);
			fa[dx] = dy; siz[dy] += siz[dx];
			w[k].push_back(dx);
		}
	}
	
	if(l == r)
	{
		if(opt[l] == 1)
		{
			if(!lst[ans][l])
			{
				int j = nxt[ans][l];
				modify(1, 1, m, l + 1, j - 1, P(x[ans][l], y[ans][l]));
				if(x[ans][l] != x[0][j] || y[ans][l] != y[0][j]) lst[1][j] = 1;
				else lst[0][j] = 1;
			}
			if(lst[ans ^ 1][l])
			{
				int j = nxt[ans ^ 1][l];
				modify(1, 1, m, l + 1, j - 1, P(x[ans ^ 1][l], y[ans ^ 1][l]));
				if(x[ans ^ 1][l] != x[0][j] || y[ans ^ 1][l] != y[0][j]) lst[1][j] = 1;
				else lst[0][j] = 1;
			}
		}
		else
		{
			if(Find(x[ans][l]) == Find(y[ans][l])) ans = 1;
			else ans = 0;
			printf("%d", ans);
		}
		for(int i = (int)w[k].size() - 1; i >= 0; i--)
		{
			int y = w[k][i];
			siz[fa[y]] -= siz[y];
			fa[y] = y;
		}
		return;
	}
	
	
	int mid = l + r >> 1;
	query(k << 1, l, mid); query(k << 1 | 1, mid + 1, r);
	
	for(int i = (int)w[k].size() - 1; i >= 0; i--)
	{
		int y = w[k][i];
		siz[fa[y]] -= siz[y];
		fa[y] = y;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &opt[i], &x[0][i], &y[0][i]);
		if(x[0][i] > y[0][i]) std::swap(x[0][i], y[0][i]);
		x[1][i] = x[0][i] + 1; y[1][i] = y[0][i] + 1;
		if(y[1][i] == n + 1) y[1][i] = x[1][i], x[1][i] = 1; 
	}
	
	if(n == 2)
	{
		bool ok = 0;
		for(int i = 1; i <= m; i++)
		{
			if(opt[i] == 1) ok ^= 1;
			else printf("%d", ok);
		}
		return 0;
	}
	
	for(int i = m; i >= 1; i--)
	{
		if(opt[i] == 2) continue;
		for(int j = 0; j <= 1; j++)
		{
			if(mp.find(P(x[j][i], y[j][i])) != mp.end()) nxt[j][i] = mp[P(x[j][i], y[j][i])];
			else nxt[j][i] = m + 1;
			mp[P(x[j][i], y[j][i])] = i;		
		}
	}
	query(1, 1, m);
}