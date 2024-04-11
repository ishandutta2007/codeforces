#include <iostream>
#include <cstdio>
#define MN 1010
#define eps 1e-10

double f[MN], s[MN], p[MN], mp[MN][MN];
bool used[MN];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		f[i] = 1e18; p[i] = 1;
		for(int j = 1; j <= n; j++) scanf("%lf", &mp[i][j]), mp[i][j] /= 100.0;
	}
	
	f[n] = 0; 
	for(int i = 1; i <= n; i++)
	{
		int id = -1;
		for(int j = 1; j <= n; j++) if(!used[j] && (id == -1 || f[j] < f[id])) id = j;
		used[id] = 1; 
		for(int j = 1; j <= n; j++)
		{
			if(used[j]) continue;
			s[j] += p[j] * mp[j][id] * f[id];
			p[j] *= (1 - mp[j][id]);
			if(1 - p[j] > eps) f[j] = (s[j] + 1) / (1 - p[j]);
		}
	}
	printf("%.10lf\n", f[1]);
}