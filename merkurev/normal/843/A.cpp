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
int vals[N];
bool used[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		vals[i] = a[i];
	}
	sort(vals, vals + n);
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(vals, vals + n, a[i] ) - vals;
	vector <vector <int>> ans;
	for (int i = 0; i < n; i++)
		if (!used[i] )
		{
			ans.push_back(vector <int> ());
			int x = i;
			while (!used[x] )
			{
				ans.back().push_back(x);
				used[x] = true;
				x = a[x];
			}
		}
	printf("%d\n", (int) ans.size() );
	for (auto &v : ans)
	{
		printf("%d", (int) v.size() );
		for (int x : v)
			printf(" %d", x + 1);
		printf("\n");
	}


	return 0;
}