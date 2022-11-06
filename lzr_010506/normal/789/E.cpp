#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
bitset<2010> f[2];
int n,m,u,cnt;
int wu[1010];
bool has[1010],ok1,ok2;
int main()
{
	n = read();
	m = read();
	for (int i = 1; i <= m; i ++)
	{
		u = read();
		if (u >= n) ok1 = 1;
		if (u <= n) ok2 = 1;
		has[u] = 1;
	}

	if(!ok1 || !ok2)
    {
        puts("-1");
        return 0;
    }

	for (int i = 0; i <= 1000; i ++)
		if (has[i])
			wu[++ cnt] = i - n;

	for (int i = 1; i <= cnt; i ++)
		f[0][wu[i] + 1000] = 1;
	if (f[0][1000])
	{
		puts("1");
		return 0;
	}
	int u = 1;
	for (int i = 2; i <= 2000000; i ++, u ^= 1)
	{
		f[u].reset();
		for (int j = 1; j <= cnt; j ++)
			if (wu[j] < 0) f[u] |= f[u ^ 1] >> (-wu[j]);
			else f[u] |= f[u ^ 1] << wu[j];
		if (f[u][1000])
		{
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}