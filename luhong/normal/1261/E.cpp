#include <cstdio>
#define MN 1010
#include <algorithm>

int n;
struct xxx{
	int h, id;
}d[MN];
int tot = 0;
int ans[MN][MN]; 

bool cmp(xxx a, xxx b) {return a.h < b.h;}

void nw(int x)
{
	++tot;
	for(int i = x; i <= n; i++) ans[tot][d[i].id] = 1, d[i].h--;
}

void solve(int x)
{
	if(x > n) return;
	if(d[x].h == 0) {solve(x + 1); return;} 
	
	if(d[n].h - d[x].h <= 1 || d[x + 1].h != 1 && d[x + 1].h != d[x + 2].h) nw(x);
	else
	{
		int H = d[x].h;
		++tot; 
		ans[tot][d[x].id] = 1; d[x].h--;
		for(int j = x + 1; j <= n; j++)
		{
			if(d[j].h != H) ans[tot][d[j].id] = 1, d[j].h--;
		}
	}
	
	int H = d[x].h;
	int j = x + 1;
	for(int i = 1; i <= H; i++)
	{
		nw(x);
		ans[tot][d[j].id] = 0; d[j].h++;
		j++;
	}
	std::sort(d + 1, d + n + 1, cmp);
	solve(x + 1);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i].h), d[i].id = i;
	std::sort(d + 1, d + n + 1, cmp);
	solve(1);
	printf("%d\n", tot);
	for(int i = 1; i <= tot; i++, puts(""))
		for(int j = 1; j <= n; j++) printf("%d", ans[i][j]);
}