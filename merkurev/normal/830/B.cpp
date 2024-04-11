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
int a[N];
vector <int> v[N];
int fn[N];


void add(int pos, int x)
{
	pos++;
	for (; pos < N; pos = ((pos - 1) | pos) + 1)
		fn[pos] += x;
}

int sum(int pos)
{
	pos++;
	int ans = 0;
	for (; pos > 0; pos = (pos & (pos - 1) ) )
		ans += fn[pos];
	return ans;
}


int getSum(int l, int r)
{
	if (l <= r)
	{
		return sum(r) - sum(l - 1);
	}
	else
	{
		return sum(N - 1) - sum(l - 1) + sum(r);
	}
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		v[a[i] ].push_back(i);
		add(i, 1);
	}

	int pos = 0;
	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i].empty() ) continue;
		int id = lower_bound(v[i].begin(), v[i].end(), pos) - v[i].begin();
		if (id == (int) v[i].size() ) id = 0;
		id--;
		if (id == -1) id += (int) v[i].size();
		int npos = v[i][id];
		ans += getSum(pos, npos);
		for (int x : v[i])
			add(x, -1);
		pos = npos;
	}
	printf("%lld\n", ans);


	return 0;
}