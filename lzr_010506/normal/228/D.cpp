#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100003;

ll a[N];
ll tag[7][10];
ll s[7][10][N * 4];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void push_up(int l, int r, int x) 
{
	int mid = (l + r) >> 1, lson = x << 1, rson = lson | 1;
	for (int z = 2; z <= 6; z ++) 
	{
		int mod = (z - 1) << 1;
		for (int i = 0; i < mod; i ++) 
			s[z][i][x] = s[z][i][lson] + s[z][(i + mid- l ) % mod][rson];	
	}
}
void build(int l, int r, int x) 
{
	if (l + 1 == r) 
	{
		for (int z = 2; z <= 6; z ++) 
			for (int i = 0; i < 2 * (z - 1); i ++) 
				s[z][i][x] = tag[z][i] * a[l];
		return;
	}	
	int mid = (l + r) >> 1, lson = x << 1, rson = lson | 1;
	build(l, mid, lson);
	build(mid, r, rson);
	push_up(l, r, x);
}
void update(int pos, ll v, int l, int r, int x) 
{
	if (l+1 == r) 
	{
		for (int z = 2; z <= 6; z ++) 
			for (int i = 0; i < 2 * (z - 1); i ++) 
				s[z][i][x] = tag[z][i]*v;
		return;		
	}
	int mid = (l + r) >> 1, lson = x << 1, rson = lson | 1;
	if (pos < mid) update(pos, v, l, mid, lson);
	else update(pos, v, mid, r, rson);
	push_up(l, r, x);
}
ll query(int L, int R, int z, int i, int l, int r, int x) 
{
	if (L <= l && r <= R) return s[z][i][x];
	int mid = (l + r) >> 1, lson = x << 1, rson = lson | 1;
	if (R <= mid) return query(L, R, z, i, l, mid, lson);
	if (L >= mid) return query(L, R, z, i, mid, r, rson);
	return query(L, mid, z, i, l, mid, lson) + query(mid, R, z, (i + mid - L) % (2 * (z - 1)), mid, r, rson);
}
int main() 
{
	int n, m, i, j;
	int t, p, v, l, r, z;
	for (int i = 2; i <= 6; i ++) 
	{
		tag[i][0] = 2;
		for (j = 1; j < 2 * (i - 1); j ++) 
			tag[i][j] = j <= i? j : 2 * i - j;
	}
	n = read();
	for (int i = 1; i <= n; i ++) 
		a[i] = read1();
	
	build(1, n + 1, 1);
	m = read();
	while (m --) 
	{
		t = read();	
		if (t == 1) 
		{
			p = read();
			v = read();
			update(p, v, 1, n + 1, 1);	
		}
		else 
		{
			l = read();
			r = read();
			z = read();
			printf("%I64d\n",query(l, r+1, z, 1, 1, n+1, 1));
		}
	}
	return 0;
}