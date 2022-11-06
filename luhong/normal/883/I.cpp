#include <cstdio>
#include <algorithm>

int a[301000];
int f[301000], s[301000];
int n, k; 

bool check(int x)
{
	int l = 1;
	f[0] = s[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		while(a[i] - a[l] > x) l++;
		if(i >= k) f[i] = s[i - k] - (l - 2 == -1 ? 0 : s[l - 2]) > 0;
		s[i] = s[i - 1] + f[i];
	}
	return f[n];
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1);
	int l = 0, r = 1e9;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);
 }