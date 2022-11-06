#include <iostream>
#include <cmath>
#include <cstdio>
#define eps 1e-8

struct xxx{
	double x, y;
	xxx(){}
	xxx(double a, double b) {x = a; y = b;}
} a[5][7];
int o[5];

xxx operator + (xxx a, xxx b) {return xxx(a.x + b.x, a.y + b.y);}
xxx operator - (xxx a, xxx b) {return xxx(a.x - b.x, a.y - b.y);}
double mod(xxx a) {return sqrt(a.x * a.x + a.y * a.y);}
xxx trans(xxx a, double len)
{
	double d = mod(a);
	a.x *= len / d; a.y *= len / d;
	return a;
}

void calc(xxx a, double r1, xxx b, double r2, xxx &Ans1, xxx &Ans2)
{
	double d = mod(a - b);
	double d1 = ((r1 * r1 - r2 * r2) / d + d) / 2;
	xxx c = trans(b - a, d1), C = b - a;
	double len = sqrt(r1 * r1 - d1 * d1);
	Ans1 = a + c + trans(xxx(-C.y, C.x), len);
	Ans2 = a + c + trans(xxx(C.y, -C.x), len);
}

int n; double x[4], y[4], r[4];

double Abs(double x) {return x > 0 ? x : -x;}

void add(int x, xxx b)
{
	for(int i = 1; i <= o[x]; i++)
		if(Abs(a[x][i].x - b.x) <= eps && Abs(a[x][i].y - b.y) <= eps) return;
	a[x][++o[x]] = b;
}

int fa[4]; 
int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lf%lf%lf", &x[i], &y[i], &r[i]), fa[i] = i;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
		{
			xxx a = xxx(x[i], y[i]), b = xxx(x[j], y[j]), Ans1, Ans2;
			if(Abs(r[i] - r[j]) - eps <= mod(a - b) && mod(a - b) <= r[i] + r[j] + eps)
			{
				calc(a, r[i], b, r[j], Ans1, Ans2);
				add(i, Ans1); add(i, Ans2); add(j, Ans1); add(j, Ans2);
				add(4, Ans1); add(4, Ans2);
				if(Find(i) != Find(j)) fa[Find(i)] = Find(j);
			}
		}
	int ans = 1 - o[4];
	for(int i = 1; i <= n; i++) ans += o[i];
	for(int i = 1; i <= n; i++) if(Find(i) == i) ans++;
	printf("%d\n", ans);
}