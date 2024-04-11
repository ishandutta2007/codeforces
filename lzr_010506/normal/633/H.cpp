#include <bits/stdc++.h>
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;

int n, m, Q, p, Rn;
int Count[30010], rk[30010], rka[30010], a[30010], fb[60010], ans[30010], tag[120010], t1[120010], t2[120010];

struct Node
{
	int l, r, id;
	bool operator < (const Node &B) const
	{
		return l / p < B.l / p || l / p == B.l / p && r < B.r;
	}
}q[30010];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int GetRank(int x)
{
	int l = 1, r = Rn;
	while(l ^ r)
	{
		int mid = (l + r) >> 1;
		if(rk[mid] < x) l = mid + 1;
		else r = mid;
	}
	return l;
}

void PushUp(int rt)
{
	t1[rt] = (t1[ls] + t1[rs]) % m;
	t2[rt] = (t2[ls] + t2[rs]) % m;
}

void shift(int rt, int shift)
{
	int nowt1 = (t2[rt] * fb[Rn + shift] + t1[rt] * fb[Rn + shift + 1]) % m;
	int nowt2 = (t2[rt] * fb[Rn + shift - 1] + t1[rt] * fb[Rn + shift]) % m;
	t1[rt] = nowt1;
	t2[rt] = nowt2;
}

void PushDown(int rt)
{
	if(tag[rt])
	{
		tag[ls] += tag[rt];
		tag[rs] += tag[rt];
		shift(ls, tag[rt]);
		shift(rs, tag[rt]);
		tag[rt] = 0;
	}
}

void Add(int X, int l, int r, int rt)
{
	if(l == r)
	{
		t2[rt] = rk[l] % m * fb[Rn + tag[rt]] % m;
		t1[rt] = rk[l] % m * fb[Rn + tag[rt] + 1] % m;
		return;
	}
	int mid = (l + r) >> 1;
	PushDown(rt);
	if(X <= mid)
	{
		Add(X, l, mid, ls);
		tag[rs] ++;
		shift(rs, 1);
	}
	else Add(X, mid + 1, r, rs);
	PushUp(rt);
}

void Remove(int X, int l, int r, int rt)
{
	if(l == r)
	{
		t1[rt] = t2[rt] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	PushDown(rt);
	if(X <= mid)
	{
		Remove(X, l, mid, ls);
		tag[rs] --;
		shift(rs, -1);
	}
	else Remove(X, mid + 1, r, rs);
	PushUp(rt);
}

void Mo_Add(int k)
{
	if(!Count[k] ++) Add(k, 1, Rn, 1);
}

void Mo_Remove(int k)
{
	if(!-- Count[k]) Remove(k, 1, Rn, 1);
}

int main()
{
	n = read();
	m = read();
	Rn = 0;
	for(int i = 1; i <= n; i ++)
		a[i] = read(), rk[++ Rn] = a[i];
	sort(rk + 1, rk + Rn + 1);
	int pp = 1;
	for(int i = 2; i <= Rn; i ++)
		if(rk[i] != rk[i - 1])
			rk[++ pp] = rk[i];
	Rn = pp;
	Q = read();
	for(int i = 1; i <= Q; i ++)
		q[i].l = read(), q[i].r = read(), q[i].id = i;
	p = sqrt(n);
	sort(q + 1, q + Q + 1);
	fb[Rn] = 0;
	fb[Rn + 1] = 1;
	for(int i = 2; i <= Rn; i ++)
		fb[Rn + i] = (fb[Rn + i - 1] + fb[Rn + i - 2]) % m;
	for(int i = 1; i <= Rn; i ++)
		fb[Rn - i] = (fb[Rn - i + 2] - fb[Rn - i + 1] + m) % m;
	for(int i = 1; i <= n; i ++)
		rka[i] = GetRank(a[i]);

	int l = 1, r = 0;
	for(int i = 1; i <= Q; i ++)
	{
		while(r > q[i].r) Mo_Remove(rka[r --]);
		while(r < q[i].r) Mo_Add(rka[++ r]);
		while(l < q[i].l) Mo_Remove(rka[l ++]);
		while(l > q[i].l) Mo_Add(rka[-- l]);
		ans[q[i].id] = t1[1];
	}

	for(int i = 1; i <= Q; i ++)
		cout << ans[i] << endl;

	return 0;
}