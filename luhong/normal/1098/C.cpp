#include <cstdio>
#include <cstring>

int n; long long s;
int cnt[101000];

bool check(int k)
{
	long long sum = 0;
	
	for(int i = 1; i <= n; i++)
	{
		cnt[i] = 1;
		sum += i;
	}
	
	int j = 1; long long w = 1;
	
	for(int i = n; i > j; i--)
	{
		while(cnt[j] == w) j++, w *= k;
		if(i <= j) return 0;
		int ad = i - j;
		cnt[i]--;
		if(sum - ad <= s)
		{
			cnt[j + (s - (sum - ad))]++;
			return 1;
		}
		else
		{
			sum -= ad;
			cnt[j]++;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%lld", &n, &s);
	if(s == 1ll * n * (n + 1) / 2)
	{
		puts("Yes");
		for(int i = 1; i < n; i++) printf("%d ", i);
		return 0;
	}
	if(s > 1ll * n * (n + 1) / 2) return 0 * puts("No");
	
	int l = 2, r = n;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	
	if(r == n) return 0 * puts("No");
	check(r);
	
	puts("Yes");
	int w = 1;
	
	for(int i = 2; i <= n; i++)
	{
		int x = 0;
		for(int j = 1; j <= cnt[i]; j++) 
		{
			printf("%d ", w - x);
			if(j % r == 0) x++;
		}
		w += cnt[i];
	}
	
	return 0;
}