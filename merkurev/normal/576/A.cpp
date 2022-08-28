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


const int maxn = (int) 1e3 + 100;
bool isP[maxn];

void solve()
{
	int n;
	scanf("%d", &n);
	memset(isP, true, sizeof isP);
	
	vector <int> ans;
	for (int i = 2; i <= n; i++)
	{
		if (!isP[i] )
			continue;
		for (int j = i * i; j <= n; j += i)
			isP[j] = false;
		int x = i;
		while (x <= n)
		{
			ans.push_back(x);
			x *= i;
		}
	}
	printf("%d\n", (int) ans.size() );

	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d ", ans[i] );
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}