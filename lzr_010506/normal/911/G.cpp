#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll unsigned long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int maxn = 2e5 + 10;
int a[maxn]; int tmp[100];
struct node 
{
	short cg[101];
}T[maxn << 2];
void pushdown(int rt) 
{
	rep(i, 1, 100) tmp[i] = T[rt].cg[T[rt << 1].cg[i]]; 
	rep(i, 1, 100) T[rt << 1].cg[i] = tmp[i];
	rep(i, 1, 100) tmp[i] = T[rt].cg[T[rt << 1 | 1].cg[i]]; 
	rep(i, 1, 100) T[rt << 1 | 1].cg[i] = tmp[i];
	rep(i, 1, 100) T[rt].cg[i] = i;
}
void build(int rt, int l, int r) 
{
	rep(i, 1, 100) T[rt].cg[i] = i;
	if (l == r) return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}
void change(int rt, int l, int r, int lq, int rq, int x, int y) 
{
	if (l == lq && r == rq) 
	{
		rep(i, 1, 100)
			if (T[rt].cg[i] == x) T[rt].cg[i] = y;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if (rq <= mid) change(rt << 1, l, mid, lq, rq, x, y);
	else if (lq > mid) change(rt << 1 | 1, mid + 1, r, lq, rq, x, y);
	else change(rt << 1, l, mid, lq, mid, x, y), change(rt << 1 | 1, mid + 1, r, mid + 1, rq, x, y);
}
void print(int rt, int l, int r) 
{
	if (l == r) return void(printf("%d ", T[rt].cg[a[l]]));
	int mid = l + r >> 1;
	pushdown(rt);
	print(rt << 1, l, mid);
	print(rt << 1 | 1, mid + 1, r);
}
int main() 
{
	int n; 
	n = read();
	rep(i, 1, n) a[i] = read();
	build(1, 1, n);
	int m = read();
	while (m --) 
	{
		int l, r, x, y;
		l = read();
		r = read();
		x = read();
		y = read();
		change(1, 1, n, l, r, x, y);
	}
	print(1, 1, n);
}