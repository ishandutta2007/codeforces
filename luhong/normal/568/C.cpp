#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#define MN 410

std::bitset<404> f[MN];
char s[MN], ans[MN], c[MN];
int n, m, l, a[MN];
bool flag = 0;
int fc[MN], fv[MN], gc[MN], gv[MN];

void floyd()
{
	for(int k = 1; k <= 2 * n; k++)
		for(int i = 1; i <= 2 * n; i++)
			if(f[i][k]) f[i] |= f[k];
}

void update(int x)
{
	for(int i = 1; i <= n; i++)
		if(a[i] == -1)
		{
			if(f[2 * x - 1 + a[x]][2 * i - 1]) a[i] = 0;
			if(f[2 * x - 1 + a[x]][2 * i]) a[i] = 1;
		}
}

bool check(int x)
{
	if(f[2 * x - 1 + a[x]][2 * x - 1 + (a[x] ^ 1)]) return 0;
	for(int i = 1; i <= n; i++)
		if(a[i] == -1)
		{
			if(f[2 * x - 1 + a[x]][2 * i - 1] && gv[i] == l + 1) return 0;
			if(f[2 * x - 1 + a[x]][2 * i] && gc[i] == l + 1) return 0;
		}
	return 1;
}

int main()
{
	scanf("%s", s + 1); l = strlen(s + 1);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int a, b; char c[2], d[2]; 
		scanf("%d%s%d%s", &a, c, &b, d);
		if(c[0] == 'V' && d[0] == 'V') f[2 * a - 1][2 * b - 1] = f[2 * b][2 * a] = 1;
		if(c[0] == 'V' && d[0] == 'C') f[2 * a - 1][2 * b] = f[2 * b - 1][2 * a] = 1;
		if(c[0] == 'C' && d[0] == 'V') f[2 * a][2 * b - 1] = f[2 * b][2 * a - 1] = 1;
		if(c[0] == 'C' && d[0] == 'C') f[2 * a][2 * b] = f[2 * b - 1][2 * a - 1] = 1;
	}
	floyd();
	scanf("%s", c + 1); 
	for(int i = 1; i <= n; i++)
	{
		fv[i] = fc[i] = gv[i] = gc[i] = l + 1;
		for(int j = l; j >= c[i] - 'a' + 1; j--)
		{
			if(s[j] == 'V') fv[i] = j;
			else fc[i] = j;
		}
		for(int j = l; j >= 1; j--)
		{
			if(s[j] == 'V') gv[i] = j;
			else gc[i] = j;
		}
	}
	bool ok;
	for(int i = n; i >= 0; i--)
	{
		memset(a, -1, sizeof(a));
		ok = 1;
		for(int j = 1; j <= i; j++)
		{
			if(fv[j] < fc[j])
			{
				ans[j] = fv[j] + 'a' - 1;
				if(a[j] == 1) {ok = 0; break;}
				a[j] = 0;
			}
			else
			{
				ans[j] = fc[j] + 'a' - 1;
				if(a[j] == 0) {ok = 0; break;}
				a[j] = 1;
			}
			if(!check(j)) {ok = 0; break;}
			update(j);
		}
		if(!ok) continue;
		ok = 1;
		for(int j = i + 1; j <= n; j++)
		{
			int FV = l + 1, FC = l + 1;
			if(j == i + 1)
			{
				for(int j = l; j > c[i + 1] - 'a' + 1; j--)
				{
					if(s[j] == 'V') FV = j;
					else FC = j;
				}
			}
			else FV = gv[j], FC = gc[j];
			if(a[j] != -1)
			{
				if(a[j] == 0) 
				{
					if(FV == l + 1) {ok = 0; break;}
					ans[j] = FV + 'a' - 1;
				}
				else 
				{
					if(FC == l + 1) {ok = 0; break;}
					ans[j] = FC + 'a' - 1;
				}
				continue;
			}
			if(FV < FC)
			{
				a[j] = 0;
				if(FV <= l && check(j))
				{
					ans[j] = FV + 'a' - 1;
					update(j); continue;
				}
				a[j] = 1;
				if(FC <= l && check(j))
				{
					ans[j] = FC + 'a' - 1;
					update(j); continue;
				}
				ok = 0; break;
			}
			else
			{
				a[j] = 1;
				if(FC <= l && check(j))
				{
					ans[j] = FC + 'a' - 1;
					update(j); continue;
				}
				a[j] = 0;
				if(FV <= l && check(j))
				{
					ans[j] = FV + 'a' - 1;
					update(j); continue;
				}
				ok = 0; break;
			}
		}
		if(ok) break;
	}
	if(ok) printf("%s", ans + 1);
	else puts("-1");
}