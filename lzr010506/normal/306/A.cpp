#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n, m, a[110];

int main()
{
	n = read();
	m = read();
	while(n)
	for(int i = m; i >= 1; i --)
		if(n)
		{
			a[i] ++;
			n --;
		}		
	for(int i = 1; i <= m; i ++)
		printf("%d ", a[i]);
	return 0;
}