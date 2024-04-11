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
char s[N];
string x = "Bulbasaur";
int cnt[300];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		cnt[s[i] ]++;
	int ans = 0;
	while (true)
	{
		bool bad = false;
		for (char c : x)
		{
			if (cnt[c] == 0)
			{
				bad = true;
				break;
			}
			cnt[c]--;
		}
		if (bad) break;
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}