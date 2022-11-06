#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <vector>

int n, m, s[101000], r[101000];
int cnt[101000], p[101000];
std::vector<int> v[101000];
std::vector<int> sum[101000];

bool cmp(int a, int b) {return cnt[a] < cnt[b];}
bool cmp2(int a, int b) {return a > b;}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &s[i], &r[i]);
		cnt[s[i]]++;
		v[s[i]].push_back(r[i]);
	}
	for(int i = 1; i <= m; i++) std::sort(v[i].begin(), v[i].end(), cmp2);
	for(int i = 1; i <= m; i++)
	{
		p[i] = i;
		int S = v[i].size();
		int s = 0;
		for(int j = 0; j < S; j++)
			s += v[i][j], sum[i].push_back(s);
	}
	std::sort(p + 1, p + m + 1, cmp);
	int j = 0, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		while(j <= m && cnt[p[j]] < i) j++;
		int now = 0;
		for(int k = j; k <= m; k++)
		{
			if(sum[p[k]][i - 1] >= 0) now += sum[p[k]][i - 1];
		}
		ans = std::max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}