#include <bits/stdc++.h>
#define ls i << 1
#define rs i << 1 | 1
using namespace std;
const int N = 100010;

int n, A[N], nm[N];

struct Node
{
	int l,r,mx,Lazy;
}tree[N << 2];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void pushdown(int i)
{
	if(!tree[i].Lazy || tree[i].l == tree[i].r)return;
	tree[ls].mx += tree[i].Lazy;
	tree[ls].Lazy += tree[i].Lazy;
	tree[rs].mx += tree[i].Lazy;
	tree[rs].Lazy += tree[i].Lazy;
	tree[i].Lazy = 0;
}

void build(int i,int l,int r)
{
	tree[i].l = l;
	tree[i].r = r;
	tree[i].Lazy = 0;
	if(l == r)
	{
		tree[i].mx = A[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	tree[i].mx = max(tree[ls].mx, tree[rs].mx);
}

void update(int i,int l,int r,int x)
{
	if(l <= tree[i].l && tree[i].r <= r)
	{
		tree[i].mx += x;
		tree[i].Lazy += x;
		return;
	}
	pushdown(i);
	int mid = tree[i].l + tree[i].r >> 1;
	if(l <= mid) update(ls, l, r, x);
	if(r > mid) update(rs, l, r, x);
	tree[i].mx = max(tree[ls].mx,tree[rs].mx);
}

int query(int i,int l,int r)
{
	if(l <= tree[i].l && tree[i].r <= r) return tree[i].mx;
	pushdown(i);
	int mid = tree[i].l + tree[i].r >> 1,ans = 0;
	if(l <= mid) ans = max(ans, query(ls, l, r));
	if(r > mid) ans = max(ans, query(rs, l, r));
	return ans;
}

int c[N];

void add(int x)
{
	while(x <= n + 1)
	{
		c[x] ++;
		x += x & (-x);
	}
}
int query(int x)
{
	int ans = 0;
	while(x)
	{
		ans += c[x];
		x -= x & (-x);
	}
	return ans;
}

int calc(int x)
{
	int l = 1, r = n + 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(query(mid) >= x)r = mid;
		else l = mid + 1;
	}
	return nm[l];
}


int main()
{
	n = read();
	A[1] = n + 1;
	nm[1] = -1;
	add(1);
	build(1, 1, n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int d,opt,x;
		d = read();
		opt = read();
		if(opt == 1) nm[d + 1] = read(), add(d + 1), update(1, 1, d + 1, 1);
		else update(1, 1, d + 1, -1);
		int l = 1, r = n + 1;
		while(l < r)
		{
			int mid = (l + r >> 1) + 1;
			if(query(1, mid, n + 1) > 0) l = mid;
			else r = mid - 1;
		}
		printf("%d\n",calc(query(l)));
	}
	return 0;
}