#include <cstdio>
#include <map>

using std::map;
map<int, int> mp;
int a[101000], b[101000];

int main()
{
	int n, m, aaa;
	scanf("%d%d", &n, &aaa);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d%d", &m, &aaa);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
	int ans = 2;
	for(int i = 1; i <= 1000000000; i <<= 1)
	{
		for(int j = 1; j <= n; j++) mp[a[j] % (2 * i)]++;
		for(int j = 1; j <= m; j++) mp[(b[j] + i) % (2 * i)]++;
		for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
			ans = std::max(ans, (*it).second);
		mp.clear();
	}
	printf("%d\n", ans);
	return 0;
}