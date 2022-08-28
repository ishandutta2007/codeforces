#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int maxn = (int) 1e6 + 1000;
char s[maxn];
int ans[maxn];
char answer[maxn];
int z[maxn];

void calcZ(int n)
{
	z[0] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < n; i++)
	{
		int &cur = z[i];
		if (i < r)
		{
			cur = min(r - i, z[i - l] );
		}
		while (s[cur] == s[i + cur] )
			cur++;
		if (i + cur > r)
		{
			l = i;
			r = i + cur;
		}
	}
}


int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", s);

	if (k == 1)
	{
		for (int i = 0; i < n; i++)
			answer[i] = '1';
		printf("%s\n", answer);
		return 0;
	}

	calcZ(n);
	
	for (int i = 1; i < n; i++)
	{
		int x = z[i];
		long long rr = i + x;
		int maxk = rr / i;
		if (maxk < k)
			continue;
		long long l = i * 1LL * k;
		long long r = i * 1LL * (k + 1);
		r = min(r, rr);
		if (l - 1 < maxn)
			ans[l - 1]++;
		if (r < maxn)
			ans[r]--;
	}
	answer[0] = '0';
	for (int i = 1; i < n; i++)
	{
		ans[i] += ans[i - 1];
		if (ans[i] > 0)
			answer[i] = '1';
		else
			answer[i] = '0';
	}
	
	printf("%s\n", answer);

	return 0;
}