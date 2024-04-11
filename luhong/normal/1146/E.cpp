#include <cstdio>
#include <iostream>
#define MN 201000
#define T 100001

int rev[4 * MN], type[4 * MN];
int a[MN], Ans[MN];

void pushdown(int x)
{
	if(type[x] != -1)
	{
		rev[x << 1] = rev[x << 1 | 1] = 0;
		type[x << 1] = type[x << 1 | 1] = type[x] ^ rev[x];
	}
	else rev[x << 1] ^= rev[x], rev[x << 1 | 1] ^= rev[x];
	rev[x] = 0; type[x] = -1;
}

int Mid(int l, int r)
{
	if((l + r) & 1) return (l + r - 1) / 2;
	else return (l + r) / 2;
}

void build(int x, int l, int r)
{
	if(l == r) {type[x] = l > 0 ? 1 : 0; return;}
	type[x] = -1; int mid = Mid(l, r);
	build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
}

void modify(int x, int l, int r, int L, int R, int t)
{
	if(l == L && r == R) 
	{
		if(t == -1) rev[x] ^= 1;
		else rev[x] = 0, type[x] = t;
		return;
	}
	pushdown(x); int mid = Mid(l, r);
	if(R <= mid) modify(x << 1, l, mid, L, R, t);
	else if(L > mid) modify(x << 1 | 1, mid + 1, r, L, R, t);
	else modify(x << 1, l, mid, L, mid, t), modify(x << 1 | 1, mid + 1, r, mid + 1, R, t);
}

void query(int x, int l, int r)
{
	if(l == r) {Ans[l + T] = type[x] ^ rev[x]; return;}
	pushdown(x); int mid = Mid(l, r);
	query(x << 1, l, mid); query(x << 1 | 1, mid + 1, r);
}

int main()
{
	int n, q; scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, -T, T);
	for(int i = 1; i <= q; i++)
	{
		char s[2]; int x; scanf("%s%d", s, &x);
		if(s[0] == '>' && x < 0) x++;
		if(s[0] == '<' && x > 0) x--;
		int X = x > 0 ? x : -x;
		modify(1, -T, T, X + 1, T, s[0] == '>' ? 0 : 1);
		modify(1, -T, T, -T, -X - 1, s[0] == '>' ? 0 : 1);
		if(s[0] == '>' && x < 0 || s[0] == '<' && x > 0) modify(1, -T, T, -X, X, -1);
		
	}
	query(1, -T, T);
	for(int i = 1; i <= n; i++) printf("%d ", (Ans[a[i] + T] == 0 ? -1 : 1) * (a[i] > 0 ? a[i] : -a[i]));
	return 0;
}