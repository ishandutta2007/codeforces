#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int test, prime[222222], cnt, n, q, a[222222], x, y;
bool f[222222];
vector<long long> sum[222222];
multiset<long long> s;
vector<int> v;
void Init()
{
	for (int i = 2; i <= maxn; i++)
	{
		if (!f[i])
		{
			prime[++cnt] = i;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= maxn; j++)
		{
			f[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}
int main()
{
	Init();
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &q); v.clear();
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0 && !f[n / i]) v.push_back(i); 
		}
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		s.clear();
		for (int i = 0; i < v.size(); i++) 
		{
			sum[v[i]].resize(v[i]);
			for (int j = 0; j < v[i]; j++) sum[v[i]][j] = 0;
			for (int j = 0; j < n; j++)
			{
				sum[v[i]][j % v[i]] += a[j];
			}
			for (int j = 0; j < v[i]; j++) sum[v[i]][j] *= v[i];
			for (int j = 0; j < v[i]; j++) s.insert(sum[v[i]][j]);
		}
		printf("%lld\n", *s.rbegin());
		while(q--)
		{
			scanf("%d%d", &x, &y); x--;
			for (int i = 0; i < v.size(); i++)
			{
				s.erase(s.find(sum[v[i]][x % v[i]]));
				sum[v[i]][x % v[i]] += (1ll * (y - a[x]) * v[i]);
				s.insert(sum[v[i]][x % v[i]]);
			}
			a[x] = y;
			printf("%lld\n", *s.rbegin());
		}
	}
	return 0;
}