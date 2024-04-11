#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MN 101000

typedef long long ll;
ll w[MN], lazy[MN], f[MN];
int ls[MN], rs[MN], Rand[MN], siz[MN], rt = 0, tot = 0;

void add(int x, ll v) {lazy[x] += v; w[x] += v;}

void pushdown(int x) {if(lazy[x]) {add(ls[x], lazy[x]), add(rs[x], lazy[x]), lazy[x] = 0;}}
void pushup(int x) {siz[x] = siz[ls[x]] + siz[rs[x]] + 1;}

void split(int x, int k, int &rt1, int &rt2)
{
	if(!x) {rt1 = rt2 = 0; return;}
	pushdown(x);
	if(siz[ls[x]] >= k)
	{
		split(ls[x], k, rt1, rt2);
		ls[x] = rt2; rt2 = x; pushup(x);
	}
	else
	{
		split(rs[x], k - siz[ls[x]] - 1, rt1, rt2);
		rs[x] = rt1; rt1 = x; pushup(x);
	}
}

int merge(int rt1, int rt2)
{
	if(!rt2) return rt1;
	if(!rt1) return rt2;
	if(Rand[rt1] < Rand[rt2])
	{
		pushdown(rt1);
		rs[rt1] = merge(rs[rt1], rt2);
		pushup(rt1);
		return rt1;
	}
	else
	{
		pushdown(rt2);
		ls[rt2] = merge(rt1, ls[rt2]);
		pushup(rt2);
		return rt2;
	}
}

void ins(int x, ll v)
{
	int rt1, rt2; ++tot;
	split(rt, x, rt1, rt2);
	Rand[tot] = rand(); siz[tot] = 1; w[tot] = v;
	rt = merge(merge(rt1, tot), rt2);
}

void modify(int x, ll v)
{
	int rt1, rt2; 
	split(rt, x, rt1, rt2); 
	add(rt2, v);
	rt = merge(rt1, rt2); 
}

void del(int x)
{
	int rt1, rt2, rt3, rt4;
	split(rt, x, rt1, rt2);
	split(rt1, x - 1, rt3, rt4);
	rt = merge(rt3, rt2);
}

void Find(int x, int a, int &S)
{
	if(!x) return;
	pushdown(x);
	if(w[x] <= 1ll * a * (S + siz[ls[x]] + 1)) Find(ls[x], a, S);
	else S += siz[ls[x]] + 1, Find(rs[x], a, S);
}

void query(int x, int S)
{
	if(!x) return;
	pushdown(x);
	f[S + siz[ls[x]] + 1] = w[x];
	query(ls[x], S); query(rs[x], S + siz[ls[x]] + 1);
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int a; scanf("%d", &a);
		int S = 0; Find(rt, a, S);
		ins(S, 1ll * S * a); modify(S, a);
	}
	query(rt, 0);
	ll Ans = 0, now = 0;
	for(int i = 1; i <= n; i++) now = std::max(now + f[i], 0ll), Ans = std::max(Ans, now);
	printf("%lld\n", Ans);
}