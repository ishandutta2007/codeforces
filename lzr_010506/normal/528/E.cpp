#include <bits/stdc++.h>
using namespace std;
#define inf 999999999
typedef double db;
const db eps = 1e-9;
const int NN = 6005;
int n;
struct point
{
	db x, y;
	point(db a = 0, db b = 0) {x = a; y = b;}
	friend db operator *(point a,point b)
	{
		return a.x * b.y - b.x * a.y;
	}
	friend point operator +(point a,point b)
	{
		a.x += b.x;
		a.y += b.y;
		return a;
	}
};
struct line
{
	db a, b, c;
	void in()
	{
		scanf("%lf%lf%lf", &a, &b, &c);
		if (a < 0) a = -a, b = -b, c = -c;
	}
	friend bool operator <(line x,line y)
	{
		db k1 = fabs(x.b) < eps ? inf : -x.a / x.b;
		db k2 = fabs(y.b) < eps ? inf : -y.a / y.b;
		return k1 > k2;
	}
} q[NN];
point pdl(line p,line q)
{
	db A1 = p.a, B1 = p.b, C1 = p.c;
	db A2 = q.a, B2 = q.b, C2 = q.c;
	db tmp = A1 * B2 - A2 * B1;
	db x = (B2 * C1 - B1 * C2) / tmp;
	db y = (A1 * C2 - A2 * C1) / tmp;
	return point(x, y);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) q[i].in();
	sort(q + 1, q + n + 1);
	for (int i = 1; i <= n; i ++) q[i + n] = q[i];
	db res = 0;
	for (int i = 1; i <= n; i ++)
	{
		point P(0, 0);
		for (int j = 1; j < n; j ++)
		{
			point Q = pdl(q[i],q[i + j]);
			res += P * Q;
			P = P + Q;
		}
	}
	res = fabs(res) * 0.5;
	db tot = (db)n * (n - 1) * (n - 2) / 6.0;
	printf("%.6f\n",res/tot);
	return 0;
}