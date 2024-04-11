#include <iostream>
#include <cstdio>
#include <cstring> 
#include <algorithm>
#define MN 401000

int s[MN], lazy[MN];
int b[MN], N;
int n, s1, s2;
int v[MN];

int Abs(int x) {return x > 0 ? x : -x;}
void add(int x) {s[x] = 0; lazy[x] = 1;}
void pd(int x) {if(lazy[x]) add(x << 1), add(x << 1 | 1), lazy[x] = 0;}
void pu(int x) {s[x] = s[x << 1] | s[x << 1 | 1];}

void modify(int x, int l, int r, int L, int R, int v)
{
	if(l == L && r == R) 
	{
		if(v == 1) s[x] = 1;
		else add(x); 
		return;
	}
	pd(x); int mid = l + r >> 1;
	if(R <= mid) modify(x << 1, l, mid, L, R, v);
	else if(L > mid) modify(x << 1 | 1, mid + 1, r, L, R, v);
	else modify(x << 1, l, mid, L, mid, v), modify(x << 1 | 1, mid + 1, r, mid + 1, R, v);
	pu(x);
}

int L(int x) {return std::lower_bound(b + 1, b + N + 1, x) - b;}
int U(int x) {return std::upper_bound(b + 1, b + N + 1, x) - b;}

bool solve(int x)
{
	memset(s, 0, sizeof(s)); memset(lazy, 0, sizeof(lazy));
	modify(1, 1, N, L(s1), L(s1), 1);
	for(int i = 1; i <= n; i++)
	{
		if(Abs(v[i] - v[i - 1]) <= x && s[1]) modify(1, 1, N, L(v[i - 1]), L(v[i - 1]), 1);
		if(L(v[i] - x) - 1 >= 1) modify(1, 1, N, 1, L(v[i] - x) - 1, 0);
		if(U(v[i] + x) <= N) modify(1, 1, N, U(v[i] + x), N, 0);
	}
	return s[1];
}

int main()
{
	scanf("%d%d%d", &n, &s1, &s2);
	
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]), b[++N] = v[i];
	v[0] = s2; b[++N] = s1; b[++N] = s2;
	
	std::sort(b + 1, b + N + 1); N = std::unique(b + 1, b + N + 1) - b - 1;
	
	int l = Abs(s2 - s1), r = (int)1e9 + 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(solve(mid)) r = mid;
		else l = mid + 1; 
	}
	printf("%d\n", r);
}