#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define N 200010
char str[N], pat[N];
int a[N], n, m, c[N];
bool check(int x)
{
	for(int i = 1; i <= x; i ++)
		c[ a[i] ] = 0;
	for(int i = x + 1; i <= n; i ++)
		c[ a[i] ] = 1;
	int j = 1;
	for(int i = 1; i <= n; i ++)
	{
		if(!c[i]) continue;
		if(str[i] == pat[j])
		{
			j ++;
			if(j == m + 1) return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%s%s", str + 1, pat + 1);
	n = strlen(str + 1);
	m = strlen(pat + 1);
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	int l = 0, r = n;
	while(l + 1 < r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << l;
	return 0;
}