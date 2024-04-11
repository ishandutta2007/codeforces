#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <cstdlib>
#define MN 101000

typedef long long ll;

struct xxx {
	ll x, y; double k;
	xxx(){}
	xxx(ll a, ll b, double c) {x = a; y = b; k = c;}
};

typedef std::set<xxx>::iterator IT;

std::set<xxx> st;

int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
int siz[MN], son[MN];
ll f[MN], a[MN], b[MN];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

int Q;

bool operator < (xxx a, xxx b) {return Q ? a.k < b.k : a.x < b.x;}
xxx operator - (xxx a, xxx b) {return xxx(a.x - b.x, a.y - b.y, 0);}
double operator / (xxx a, xxx b) {return (double)a.x * b.y - (double)a.y * b.x;}

void add(xxx a)
{
	IT it, it2, it3;
	it = st.lower_bound(a);
	if(it != st.end() && it -> x == a.x)
	{
		if(it -> y > a.y) st.erase(it);
		else return;
	}
	st.insert(a); it = st.lower_bound(a);
	if(it != st.begin())
	{
		it--; it2 = it; it++; it++; it3 = it; it--;
		if(it3 != st.end())
			if((*it - *it2) / (*it3 - *it) <= 0)
			{
				st.erase(a); return;
			}
	}
	while(1)
	{
		if(it != st.begin()) it--, it2 = it;
		else break;
		if(it != st.begin()) it--, it3 = it;
		else break;
		it++; it++;
		if((*it2 - *it3) / (*it - *it2) <= 0) st.erase(it2);
		else break;
	}
	it = st.lower_bound(a);
	while(1)
	{
		it++;
		if(it != st.end()) it2 = it;
		else break;
		it++;
		if(it != st.end()) it3 = it;
		else break;
		it--; it--;
		if((*it2 - *it) / (*it3 - *it2) <= 0) st.erase(it2);
		else break;
	}
	double k1 = 0, k2 = 0;
	it = st.lower_bound(a); it++; it3 = it; it--; 
	if(it3 == st.end()) k2 = 1e18; 
	else k2 = 1.0 * (it3 -> y - it -> y) / (it3 -> x - it -> x);
	if(it != st.begin())
	{
		it--; it3 = it; it++;
		k1 = 1.0 * (it3 -> y - it -> y) / (it3 -> x - it -> x);
		xxx v = xxx(it3 -> x, it3 -> y, k1);
		st.erase(it3); st.insert(v);
	}
	st.erase(a); a.k = k2; st.insert(a);
}

xxx query(double k)
{
	Q = 1; xxx v = xxx(0, 0, k);
	IT it = st.lower_bound(v); Q = 0;
	return *it;
}

void dfs1(int x, int fa)
{
	siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue; 
		dfs1(to[i], x);
		siz[x] += siz[to[i]];
		if(siz[to[i]] > siz[son[x]]) son[x] = to[i];
	}
}

void dfs2(int x, int fa)
{
	add(xxx(b[x], f[x], 0));
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		dfs2(to[i], x);
	}
}

void dfs3(int x, int fa, bool ok)
{
	bool okk = 0;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa || to[i] == son[x]) continue;
		dfs3(to[i], x, 0);
		okk = 1;
	}
	if(!okk && !son[x]) {f[x] = 0; return;}
	if(son[x]) dfs3(son[x], x, 1), add(xxx(b[son[x]], f[son[x]], 0)); 
	for(int i = h[x]; i; i = nxt[i]) if(to[i] != fa && to[i] != son[x]) dfs2(to[i], x);
	xxx v = query(-a[x]); 
	f[x] = v.x * a[x] + v.y;
	if(!ok) st.clear();
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%lld", &b[i]);
	for(int i = 1; i < n; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		ins(a, b); ins(b, a);
	}
	dfs1(1, 0);  dfs3(1, 0, 0);
	for(int i = 1; i <= n; i++) printf("%lld ", f[i]);
}