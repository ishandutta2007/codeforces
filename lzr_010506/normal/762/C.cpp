#include <bits/stdc++.h>
#define ll long long
#define MN 300001
using namespace std;

int n,m,A,B,p[110002];
char a[110002],b[110002];
int main()
{
	int i,j,k;
	scanf("%s%s",a,b);
	n = strlen(a);
	m = strlen(b);
	p[m] = n;
	for (i = m - 1, j = n - 1; i; i --)
	{
		while(b[i] != a[j] && j > 0) j --;
		if (b[i] != a[j] || j < 0) break;
		p[i] = j;
		j --;
	}
	k = i + 1;
	A = -1;
	B = k;	
	if (B != 0) 
		for (i = j = 0; i < m; i ++)
		{
			while(b[i] != a[j] && j < n) j ++;
			if (b[i] != a[j] || j >= n) break;
			while (p[k] <= j || k <= i) k ++;
			if (k - i < B - A) B = k, A = i;
			if (k - i == 1) break;
			j ++;
		}
	if (B - A - 1 == m) return puts("-"),0;
	for (i = 0; i <= A; i ++) putchar(b[i]);
	for (i = B; i < m; i ++) putchar(b[i]);
}