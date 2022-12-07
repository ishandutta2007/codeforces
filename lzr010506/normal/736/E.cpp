#include <bits/stdc++.h>
using namespace std;
const int N=3007,MD=N*2,MX=MD*2;
const char ans[3]={'L', 'D', 'W'};
int n,m,mm,cur,u[MX],cnt[MX],pnt[MX],z[N],a[N],b[N],f[N][N];
int main() 
{
	scanf("%d%d",&m,&n);
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	for (int i = n; i < m; i ++) a[i] = a[n - 1];
	for (int i = 0; i < m; i ++) 
	{
		for (int j = 0; j < m; j ++) f[i][j] = int(i != j);
		b[i] = m - 1;
	}
	memset(u, 255, sizeof(u));
	for (int i = 0; i < m; i ++) 
		if (b[i] > a[i] || (i < n && b[i] != a[i])) 
		{
			for (int j = i + 1; j < m; j ++) 
			{
				cur = b[j] - a[j];
				if (j >= n) cur = max(0, cur);
				cur += MD;
				if (u[cur] != i) u[cur] = i, cnt[cur] = 1;
				else cnt[cur] ++;
			}
			for (int j = 0; j < MX - 1; j ++) pnt[j + 1] = pnt[j] + (u[j] == i ? cnt[j] : 0);
			for (int j = i + 1; j < m; j ++) 
			{
				cur = b[j] - a[j];
				if (j >= n) cur = max(0, cur);
				z[pnt[cur + MD] ++] = j;
			}
			mm = m - 1 - i;
			for (int j = 0; b[i] > a[i] && j < mm; j ++) 
			{
				f[i][z[j]] --;
				f[z[j]][i] ++;
				b[i] --;
				b[z[j]] ++;
			}
			for (int j = mm - 1; b[i] < a[i] && j >= 0; j --) 
			{
				f[i][z[j]] ++;
				f[z[j]][i] --;
				b[i] ++;
				b[z[j]] --;
			}
			if (b[i] > a[i] || (i < n && b[i] != a[i])) 
			{
				puts("no");
				return 0;
			}
		}
	puts("yes");
	for (int i = 0; i < m; i ++, puts("")) 
		for (int j = 0; j < m; j ++) 
			putchar(i == j? 'X': ans[f[i][j]]);
	return 0;
}