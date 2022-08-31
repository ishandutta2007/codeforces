#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 1e5 + 100;
int a[N], p[N];
int color[N], cnt[N];
long long sum[N];
long long ans = 0;
int sz = 0;
int n;

void recolor(int pos, int from, int to)
{
	if (pos < 0 || pos >= n) return;
	if (color[pos] != from) return;
	color[pos] = to;
	recolor(pos + 1, from, to);
	recolor(pos - 1, from, to);
}

void uni(int pos)
{
	int ca = color[pos], cb = color[pos + 1];
	if (cnt[ca] < cnt[cb] )
		recolor(pos, ca, cb);
	else
		recolor(pos + 1, cb, ca);
	sum[ca] += sum[cb];
	sum[cb] = sum[ca];
	cnt[ca] += cnt[cb];
	cnt[cb] = cnt[ca];
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		color[i] = -1;
		scanf("%d", &a[i] );
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i] );
		p[i]--;
	}

	vector <long long> answer;

	for (int it = n - 1; it >= 0; it--)
	{
		answer.push_back(ans);
		int x = p[it];
		color[x] = sz++;
		cnt[color[x] ] = 1;
		sum[color[x] ] = a[x];
		if (x != 0 && color[x - 1] != -1)
			uni(x - 1);
		if (x != n - 1 && color[x + 1] != -1)
			uni(x);
		ans = max(ans, sum[color[x] ]);
	}
	reverse(answer.begin(), answer.end() );
	for (long long x : answer)
		printf("%lld\n", x);


	return 0;
}