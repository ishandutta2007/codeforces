#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

const int m = 1500000;
int n, a[101000], b[101000];
int pri[m + 5], tot = 0;
bool ok[m + 5];
int fa[m + 5];

int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}

void init()
{
	for(int i = 2; i <= m; i++)
	{
		if(!ok[i]) pri[++tot] = i;
		for(int j = 1; j <= tot && i * pri[j] <= m; j++)
		{
			ok[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

void upd(int p)
{
	for(int k = p; k < m; k += p)
	{
		int x = Find(k), y = Find(k + 1);
		if(x != y) fa[x] = y;
	}
}

int main()
{
	init();
	for(int i = 1; i <= m; i++) fa[i] = i;
	
	scanf("%d", &n);
	bool okk = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		int x = okk == 0 ? a[i] : 2;
		int y = Find(x);
		b[i] = y;
		if(b[i] != a[i]) okk = 1;
		if(!ok[y]) upd(y);
		else
		{
			for(int j = 1; pri[j] * pri[j] <= y; j++)
			{
				if(y % pri[j] == 0)
				{
					upd(pri[j]);
					while(y % pri[j] == 0) y /= pri[j];
				}
			}
			if(y != 1) upd(y);
		}
		
	}
	
	for(int i = 1; i <= n; i++)
		printf("%d ", b[i]);
}