#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

char s[2010][2010];
int dp[2010][2010];
bool used[2010][2010];

int v[4010][2], tot = 0;
int v2[4010][2], tot2 = 0;
char c[4010]; int o = 0;

int main()
{
	int n,k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	memset(dp, 63, sizeof(dp));
	int ans = 0;
	if(s[1][1] == 'a') dp[1][1] = -1;
	else dp[1][1] = 0;
	if(dp[1][1] < k)
	{
		if(1 + 1 > ans)
		{
			ans = 1 + 1;
			tot = 0;
			++tot; v[tot][0] = 1; v[tot][1] =1;
		}
		else if(1 + 1 == ans) {++tot ; v[tot][0] = 1; v[tot][1] = 1;}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == 1 && j == 1) continue;
			if(i > 1) dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
			if(j > 1) dp[i][j] = std::min(dp[i][j], dp[i][j - 1]);
			if(s[i][j] != 'a') dp[i][j]++;
			if(dp[i][j] < k)
			{
				if(i + j > ans)
				{
					ans = i + j;
					tot = 0;
					++tot; v[tot][0] = i; v[tot][1] = j;
				}
				else if(i + j == ans) {++tot ; v[tot][0] = i; v[tot][1] = j;}
			}
		
		}
	}
	if(ans == 0)
	{
		tot++;
		v[tot][0] = 1; v[tot][1] = 1;
		printf("%c", s[1][1]);
		ans = 1 + 1;
	}
	else for(int i = 1; i < ans; i++) printf("a");
	for(int L = ans; L <= 2 * n - 1; L++)
	{
		int Min = 1222;
		for(int k = 1; k <= tot; k++)
		{
			int i = v[k][0], j = v[k][1];
			if(i < n) Min = min(Min, (s[i + 1][j] - 'a'));
			if(j < n) Min = min(Min, (s[i][j + 1] - 'a'));
		}
		printf("%c", Min + 'a');
		for(int k = 1; k <= tot; k++)
		{
			int i = v[k][0], j = v[k][1];
			if(i < n && !used[i + 1][j])
			{
				used[i + 1][j] = 1;
				if(s[i + 1][j] == Min + 'a')
				{
					tot2++;
					v2[tot2][0] = i + 1;
					v2[tot2][1] = j;
				}
			}
			if(j < n && !used[i][j + 1])
			{used[i][j + 1] = 1;
				if(s[i][j + 1] == Min + 'a')
				{
					
					tot2++;
					v2[tot2][0] = i;
					v2[tot2][1] = j + 1;
				}
			}
				
			
		}
		tot = tot2;tot2 = 0;
		for(int i = 1; i <= tot; i++) v[i][0] = v2[i][0], v[i][1] = v2[i][1];
	}
	
	
	return 0;
}