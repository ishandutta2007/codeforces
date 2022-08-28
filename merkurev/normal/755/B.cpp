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

const int N = 505;
set <string> poland, enemy;
char s[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		poland.insert(string(s) );
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%s", s);
		enemy.insert(string(s) );
	}
	int a = (int) poland.size();
	int b = (int) enemy.size();
	int c = 0;
	for (string x : poland)
		if (enemy.count(x) )
			c++;
	a -= c;
	b -= c;

	while (a + c > 0)
	{
		if (c > 0) c--;
		else a--;

		if (c > 0) c--;
		else if (b > 0) b--;
		else
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	
	return 0;
}