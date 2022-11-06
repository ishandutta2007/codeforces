#include <cstdio>
#include <cstring>
#include <map>
char s[1010000];
std::map<int, int> mp;
int main()
{
	int n; scanf("%d", &n);
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		int len = strlen(s);
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for(int j = 0; j < len; j++)
		{
			cnt[s[j] - 'a']++;
		}
		int S = 0;
		for(int j = 0; j < 26; j++)
		{
			cnt[j] %= 2;
			S |= cnt[j] << j;
		}
		for(int j = 0; j < 26; j++)
		{
			ans += mp[S ^ (1 << j)];
		}
		ans += mp[S];
		mp[S]++;
		for(int j = 0; j < len; j++) s[j] = '\0';
	}
	printf("%lld\n", ans);
	return 0;
}