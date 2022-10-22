#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int t, n, m;
int a[N][N];
int ok(char x){return x == 'R' || x == 'D' || x == 'C';}
int main()
{
	scanf("%d", &t);
	for(int amo = 1; amo <= t; amo++)
	{
		scanf("%d%d", &n, &m);
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				char w;
				while(!ok(w = getchar()));
				if(w == 'C') continue;
				if(i == n) ans += w == 'D';
				if(j == m) ans += w == 'R';
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}