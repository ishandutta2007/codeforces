#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MN 801000

int n, m = 100000;
int x[MN], y[MN], v[MN], st[MN], top = 0;
struct xxx{
	int x, y;
	xxx(){}
	xxx(int a, int b) {x = a; y = b;}
}p[MN];

xxx operator - (xxx a, xxx b) {return xxx(a.x - b.x, a.y - b.y);}
long long operator / (xxx a, xxx b) {return 1ll * a.x * b.y - 1ll * a.y * b.x;} 
double dist(xxx a, xxx b) {xxx c = a - b; return sqrt(1ll * c.x * c.x + 1ll * c.y * c.y);}

bool cmp(xxx a, xxx b) {return a.x == b.x ? a.y < b.y : a.x < b.x;}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d%d", &x[i], &y[i], &v[i]);
	int tot = 0;
	for(int i = 1; i <= n; i++)
	{
		if(x[i] - v[i] >= 0) p[++tot] = xxx(x[i] - v[i], y[i]);
		else p[++tot] = xxx(0, std::max(0, y[i] - (v[i] - x[i]))), p[++tot] = xxx(0, std::min(m, y[i] + (v[i] - x[i])));
		
		if(x[i] + v[i] <= m) p[++tot] = xxx(x[i] + v[i], y[i]);
		else p[++tot] = xxx(m, std::max(0, y[i] - (v[i] - (m - x[i])))), p[++tot] = xxx(m, std::min(m, y[i] + (v[i] - (m - x[i]))));
		
		if(y[i] - v[i] >= 0) p[++tot] = xxx(x[i], y[i] - v[i]);
		else p[++tot] = xxx(std::max(0, x[i] - (v[i] - y[i])), 0), p[++tot] = xxx(std::min(m, x[i] + (v[i] - y[i])), 0);
		
		if(y[i] + v[i] <= m) p[++tot] = xxx(x[i], y[i] + v[i]);
		else p[++tot] = xxx(std::max(0, x[i] - (v[i] - (m - y[i]))), m), p[++tot] = xxx(std::min(m, x[i] + (v[i] - (m - y[i]))), m);
	}
	std::sort(p + 1, p + tot + 1, cmp);
	for(int i = 1; i <= tot; i++)
	{
		while(top > 1 && (p[st[top]] - p[st[top - 1]]) / (p[i] - p[st[top]]) <= 0) top--;
		st[++top] = i;
	}
	int now = top;
	for(int i = tot - 1; i >= 1; i--)
	{
		while(top > now && (p[st[top]] - p[st[top - 1]]) / (p[i] - p[st[top]]) <= 0) top--;
		st[++top] = i;
	}
	st[++top] = st[2];
	double R = 0; int id;
	for(int i = 1; i <= top - 2; i++)
	{
		double a = dist(p[st[i]], p[st[i + 1]]), b = dist(p[st[i + 1]], p[st[i + 2]]), c = dist(p[st[i + 2]], p[st[i]]);
		double cos = (a * a - b * b - c * c) / (-2 * b * c), sin = sqrt(1 - cos * cos);
		if(a / sin / 2 > R) R = a / sin / 2, id = i;
	}
	for(int i = 0; i < 3; i++) printf("%d %d\n", p[st[id + i]].x, p[st[id + i]].y);
}