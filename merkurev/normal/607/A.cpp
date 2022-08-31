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
vector <pair <int, int> > v;
int a[N];
int b[N];
int ans[N];
int answer = 0;

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
		int _a, _b;
		scanf("%d%d", &_a, &_b);
		v.emplace_back(_a, _b);
	}
	sort(v.begin(), v.end() );

	for (int i = 0; i < n; i++)
	{
		a[i] = v[i].first;
		b[i] = v[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		int fd = lower_bound(a, a + n, a[i] - b[i] ) - a;
		fd--;
		if (fd == -1)
			ans[i] = 1;
		else
			ans[i] = 1 + ans[fd];
		answer = max(answer, ans[i] );
	}
	printf("%d\n", n - answer);


	return 0;
}