#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
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

const int N = (int) 3e5 + 100;
long long t[N], w[N];

priority_queue <pair <long long, long long> > down;
priority_queue <long long> up;

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &t[i], &w[i] );
	for (int i = 1; i < n; i++)
		down.push(make_pair(t[i], (w[i] - t[i] + 1)) );

	int ans = n;
	long long x = t[0];

	while (true)
	{
		while (!down.empty() && down.top().first > x)
		{
			up.push(-down.top().second);
			down.pop();
		}
		ans = min(ans, (int) up.size() + 1);
		if (up.empty() || -up.top() > x)
			break;
		x -= -up.top();
		up.pop();
	}
	printf("%d\n", ans);

	return 0;
}