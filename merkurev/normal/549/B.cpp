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


const int maxn = 105;
char f[maxn][maxn];
int a[maxn];
int cur[maxn];
vector <int> ans;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", f[i] );
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );

	while (true)
	{
		bool ch = false;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == cur[i] )
			{
				ans.push_back(i);
				ch = true;

				for (int j = 0; j < n; j++)
					if (f[i][j] == '1')
						cur[j]++;
				break;
			}
		}
		if (!ch)
			break;
	}

	printf("%d\n", (int) ans.size() );
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d\n", ans[i] + 1);

	return 0;
}