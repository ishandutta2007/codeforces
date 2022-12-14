#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

const int maxn = 3e5 + 20;
const double pi = acos(-1);

int n, m;
double cir_cos[360], cir_sin[360];
int S[maxn << 2];
struct Vector
{
	double x, y;
}V[maxn << 2];

int Ang[maxn], Len[maxn];

void update(int x)
{
	S[x] = (S[x << 1] + S[x << 1 | 1]) % 360;
	V[x].x = V[x << 1].x + V[x << 1 | 1].x * cir_cos[S[x << 1]] - V[x << 1 | 1].y * cir_sin[S[x << 1]];
	V[x].y = V[x << 1].y + V[x << 1 | 1].x * cir_sin[S[x << 1]] + V[x << 1 | 1].y * cir_cos[S[x << 1]];
}
void modify(int k,int l,int r,int o)
{
	if(l == r) S[o] = Ang[k], V[o] = (Vector){Len[k] * cir_cos[Ang[k]], Len[k] * cir_sin[Ang[k]]};
	else
	{	
		int mid = (l + r) >> 1;
		if(k <= mid) modify(k, l, mid, o << 1);
		else modify(k, mid + 1, r, o << 1 | 1);
		update(o);
	}
}
void build(int l,int r,int o)
{
	if(l == r) S[o] = Ang[l], V[o] = (Vector){1, 0};
	else
	{
		int mid = (l + r) >> 1;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
		update(o);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < 360; i++)
	{
		cir_cos[i] = cos((double) i / 360 * 2 * pi);
		cir_sin[i] = sin((double) i / 360 * 2 * pi);
	}
	for(int i = 1; i <= n; i++) Len[i] = 1;
	
	build(1, n, 1);
	
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		
		if(x == 1) Len[y] += z, modify(y, 1, n, 1);
		else (Ang[y] += 360 - z) %= 360, modify(y, 1, n, 1);
		
		printf("%.10lf %.10lf\n", V[1].x, V[1].y);
	}
	return 0;
}