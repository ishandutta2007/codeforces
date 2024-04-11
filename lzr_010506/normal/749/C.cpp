#include <bits/stdc++.h>
using namespace std;
const int N=2000010;
int n, x, q[N], f[2], c[2];
char a[N];
int main()
{
	scanf("%d%s", &n, a + 1);
	for(int i = 1; i <= n; i ++)
		c[q[i] = a[i] == 'R'] ++;
	int x = 1, y = n;
	while(c[0] && c[1])
	{
		int now = q[x ++];
		if(f[now])
		{
			c[now] --;
			f[now] --;
			continue;
		}
		f[now ^ 1] ++;
		q[++ y] = now;
	}
	if(q[y] == 1) printf("R");
	else printf("D");
}