#include <bits/stdc++.h>
using namespace std;
int m, n, ans;
char a[40][3], q[100010][10], b[40];
int sz[100010];
set<int> sll;

int chu(char *a)
{
	int x = 0;
	int sl = strlen(a);
	for(int i = 0; i < sl; i ++)
		x = x * 10 + a[i] - 'a';
	return x;
}

int main()
{
	scanf("%d %d",&m,&n);
	for(int i = 1; i <= n; i ++)
		scanf("%s %c", a[i], &b[i]);
	int l = 1, r = 2;
	q[1][0] = 'a';
	sz[1] = 1;
	while(l < r)
	{
		if(sz[l] == m) break;
		int sl = sz[l];
		int i = 0;
			for(int j = 1; j <= n; j ++)
				if(q[l][i] == b[j])
				{
					for(int k = 0; k <= sl; k ++)
						if(k < i) q[r][k] = q[l][k];
						else if(k == i) q[r][k] = a[j][0], q[r][++ k] = a[j][1];
						else if(k > i) q[r][k] = q[l][k - 1]; 
					sz[r] = sz[l] + 1;
					r ++;
				}
			
		l ++;
	}
	for(int i = r - 1; i >= 1; i --)
	{
		if(sz[i] == m)
		{
			int x = chu(q[i]);
			if(sll.count(x) == 0) ans ++;
			sll.insert(x);
		}
		else break;
	}
	printf("%d", ans);
	return 0;
}