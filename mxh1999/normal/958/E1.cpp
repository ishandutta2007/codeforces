#include <bits/stdc++.h>
using namespace std;
int R, B;
struct point
{
	int x, y;
	point() {}
	point(int _x, int _y):x(_x), y(_y) {}
	point operator -(point v) {return point(x - v.x, y - v.y);}
}sp[15], ba[15];
int to[15], dir[15];
bool cross(point u, point v) {return u.x * v.y > u.y * v.x;}
bool cro(int u, int v)
{
	int a = dir[u], b = dir[v];
	/*
	if (!(cross(sp[u] - ba[a], ba[b] - ba[a]) ^ cross(sp[v] - ba[a], ba[b] - ba[a]))) return false;
	if (!(cross(ba[a] - sp[u], sp[v] - sp[u]) ^ cross(ba[b] - sp[u], sp[v] - sp[u]))) return false;
	*/
	if (!(cross(ba[b] - ba[a], sp[u] - ba[a]) ^ cross(sp[v] - ba[a], sp[u] - ba[a]))) return false;
	if (!(cross(ba[a] - ba[b], sp[v] - ba[b]) ^ cross(sp[u] - ba[b], sp[v] - ba[b]))) return false;
	return true;
}
bool ok;
bool nnm;
void dfs(int x)
{
	bool flag;
	if (x > R)
	{
		nnm=true;
		return;
	}
	for (int i = 1; i <= B; i++)
		if (!to[i])
		{
			to[i] = x;
			dir[x] = i;
			flag = true;
			for (int j = 1; j < x; j++)
				if (cro(j, x))
				{
					flag = false;
					break;
				}
			if (flag)
			{
				dfs(x+1);
				if (nnm)	return;
			}
			to[i] = 0;
			dir[x] = 0;
		}
}
int main()
{
#ifdef _noname
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &R, &B);
	if (R != B)
	{
		puts("No");
		return 0;
	}
	for (int i = 1; i <= R; i++) scanf("%d%d", &sp[i].x, &sp[i].y);
	for (int i = 1; i <= B; i++) scanf("%d%d", &ba[i].x, &ba[i].y);
	memset(to, 0, sizeof to);
	dfs(1);
	if (nnm) puts("Yes");
	else puts("No");
	return 0;
}