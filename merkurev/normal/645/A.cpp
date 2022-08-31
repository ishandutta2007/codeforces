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

char f[2][3];
vector <char> a[2];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			scanf("%s", f[j] );
		a[i].push_back(f[0][0] );
		a[i].push_back(f[1][0] );
		a[i].push_back(f[1][1] );
		a[i].push_back(f[0][1] );
		while (a[i].back() != 'X')
			rotate(a[i].begin(), a[i].begin() + 1, a[i].end() );
		a[i].pop_back();
		while (a[i].back() != 'A')
			rotate(a[i].begin(), a[i].begin() + 1, a[i].end() );
	}
	if (a[0] == a[1] )
		printf("YES\n");
	else
		printf("NO\n");




	return 0;
}