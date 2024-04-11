#include <cstdio>
#include <iostream>
#include <algorithm>
#define MN 800100

typedef long long ll;
const int inf = 1e9;
int q1[MN], q2[MN], top1 = 0, top2 = 0; 
int n, a[MN]; 

struct xxx {
	int Min, cnt, tg1, tg2;
	ll ans;
} t[MN];

struct Qry {
	int id, l, r;
} q[MN];

long long Ans[MN];

bool cmp(Qry a, Qry b) {return a.r < b.r;}
 
void add1(int x, int v) {t[x].Min += v; t[x].tg1 += v;}
void add2(int x, int v) {t[x].ans += 1ll * t[x].cnt * v; t[x].tg2 += v;}

xxx pu(xxx a, xxx b)
{
	xxx c; c.tg1 = c.tg2 = 0;
	if(a.Min < b.Min) c.cnt = a.cnt;
	else if(a.Min == b.Min) c.cnt = a.cnt + b.cnt;
	else c.cnt = b.cnt;
	c.Min = std::min(a.Min, b.Min);
	c.ans = a.ans + b.ans;
	return c; 
}

void pd(int x)
{
	if(t[x].tg1)
	{
		add1(x << 1, t[x].tg1);
		add1(x << 1 | 1, t[x].tg1);
		t[x].tg1 = 0;
	}
	if(t[x].tg2)
	{
		if(t[x << 1].Min == t[x].Min) add2(x << 1, t[x].tg2);
		if(t[x << 1 | 1].Min == t[x].Min) add2(x << 1 | 1, t[x].tg2);
		t[x].tg2 = 0;
	}
}

void build(int x, int l, int r)
{
	t[x].cnt = r - l + 1; 
	if(l == r) return;
	int mid = l + r >> 1;
	build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
}

void modify(int x, int l, int r, int L, int R, int v, int ty)
{
	if(l == L && r == R) {if(!ty) add1(x, v); else if(t[x].Min == 0) add2(x, v); return;}
	pd(x); int mid = l + r >> 1;
	if(R <= mid) modify(x << 1, l, mid, L, R, v, ty);
	else if(L > mid) modify(x << 1 | 1, mid + 1, r, L, R, v, ty);
	else modify(x << 1, l, mid, L, mid, v, ty), modify(x << 1 | 1, mid + 1, r, mid + 1, R, v, ty);
	t[x] = pu(t[x << 1], t[x << 1 | 1]);
}

ll query(int x, int l, int r, int L, int R)
{
	if(l == L && r == R) return t[x].ans;
	pd(x); int mid = l + r >> 1;
	if(R <= mid) return query(x << 1, l, mid, L, R);
	else if(L > mid) return query(x << 1 | 1, mid + 1, r, L, R);
	else return query(x << 1, l, mid, L, mid) + query(x << 1 | 1, mid + 1, r, mid + 1, R);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int Q; scanf("%d", &Q);
	for(int i = 1; i <= Q; i++) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
	std::sort(q + 1, q + Q + 1, cmp);
	
	build(1, 1, n);
	
	int j = 1;
	top1 = top2 = 0; q1[0] = q2[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i - 1 >= 1) modify(1, 1, n, 1, i - 1, -1, 0);
		while(top1 && a[i] > a[q1[top1]])
			modify(1, 1, n, q1[top1 - 1] + 1, q1[top1], a[i] - a[q1[top1]], 0), top1--;
		q1[++top1] = i;
		
		while(top2 && a[i] < a[q2[top2]])
			modify(1, 1, n, q2[top2 - 1] + 1, q2[top2], a[q2[top2]] - a[i], 0), top2--;
		q2[++top2] = i;
		
		modify(1, 1, n, 1, i, 1, 1); 
		while(j <= Q && q[j].r == i) Ans[q[j].id] = query(1, 1, n, q[j].l, q[j].r), j++;
	}
	
	for(int i = 1; i <= Q; i++) printf("%lld\n", Ans[i]);
	return 0;
}