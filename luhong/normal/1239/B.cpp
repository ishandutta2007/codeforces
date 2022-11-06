#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define MN 601000

std::vector<int> v;
int n, sum[MN];
int s1[MN], s2[MN];
char s[MN];

int main()
{
	scanf("%d%s", &n, s + 1);
	int Min = 1e9;
	for(int i = 1; i <= n * 2; i++) 
	{
		if(i > n) s[i] = s[i - n]; 
		sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
		Min = std::min(Min, sum[i]); 
	}
	if(sum[n] != 0) return 0 * printf("0\n1 1");
	int cnt = 0;
	for(int i = 1; i <= 2 * n; i++)
	{
		s1[i] = s1[i - 1]; s2[i] = s2[i - 1];
		if(sum[i] == Min + 1) s1[i]++;
		if(sum[i] == Min + 2) s2[i]++;
		if(i <= n && sum[i] == Min) cnt++, v.push_back(i);
	}
	v.push_back(v[0] + n);
	int ans = cnt, l = 1, r = 1;
	for(int i = 0; i < (int)v.size() - 1; i++)
	{
		if(s1[v[i + 1]] - s1[v[i]] > ans)
		{
			ans = s1[v[i + 1]] - s1[v[i]];
			l = v[i] + 1; r = v[i + 1];
		}
	}
	
	v.clear(); 
	for(int i = 1; i <= n; i++)
		if(sum[i] == Min + 1) v.push_back(i);
	v.push_back(v[0] + n);
		
	for(int i = 0; i < (int)v.size() - 1; i++)
	{
		if(s2[v[i + 1]] - s2[v[i]] + cnt > ans)
		{
			ans = s2[v[i + 1]] - s2[v[i]] + cnt;
			l = v[i] + 1; r = v[i + 1];
		}
	}
	
	if(l > n) l -= n; if(r > n) r -= n;
	printf("%d\n%d %d", ans, l, r);
}