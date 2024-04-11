#include <bits/stdc++.h>
using namespace std;

#define N 300005
#define lson (pos << 1)
#define rson (pos << 1 | 1)

int n, m, tag[N * 4];
double pi = acos(-1);

struct point
{
	double x, y;
	point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	point operator +(point &p) { return point(x + p.x, y + p.y); }
	friend ostream &operator <<(ostream &out, point p)
	{ out << '(' << p.x << ", " << p.y << ')'; return out; }
} poi[N * 4];


void rotate(point &p, double a)
{
	p = point(p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a));
}

void addlen(point &p, double b)
{
	double t = sqrt(p.x * p.x + p.y * p.y);
	p.x = p.x / t * (t + b), p.y = p.y / t * (t + b);
}

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void build(int pos, int l, int r)
{
	if (l == r)
	{ poi[pos] = point(1, 0); return; }
	int mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	poi[pos] = poi[lson] + poi[rson];
}

void lazy(int pos)
{
	if (tag[pos])
	{
		tag[lson] += tag[pos]; tag[rson] += tag[pos];
		rotate(poi[lson], -pi * tag[pos] / 180);
		rotate(poi[rson], -pi * tag[pos] / 180);
		tag[pos] = 0;
	}
}

void modify(int pos, int l, int r, int x, int y)
{
	if (l == r)
	{
		addlen(poi[pos], y);
		return;
	}
	lazy(pos);
	int mid = (l + r) >> 1;
	if (x <= mid) modify(lson, l, mid, x, y);
	else modify(rson, mid + 1, r, x, y);
	poi[pos] = poi[lson] + poi[rson];
}

void add(int pos, int l, int r, int x, int y, int z)
{
	if (x <= l && r <= y)
	{
		rotate(poi[pos], -pi * z / 180);
		tag[pos] += z; return;
	}
	lazy(pos);
	int mid = (l + r) >> 1;
	if (x <= mid) add(lson, l, mid, x, y, z);
	if (y > mid) add(rson, mid + 1, r, x, y, z);
	poi[pos] = poi[lson] + poi[rson];
}

int main()
{
	cin >> n >> m;
	build(1, 1, n);
	for (int x, y, z, i = 1; i <= m; ++i)
	{
		x = read(), y = read(), z = read();
		if (x == 1) modify(1, 1, n, y, z);
		else add(1, 1, n, y, n, z);
		printf("%.9lf %.9lf\n", poi[1].x, poi[1].y);
	}
	return 0;
}