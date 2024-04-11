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

char answer[4] = "BGR";

int getId(char c)
{
	if (c == 'B')
		return 0;
	if (c == 'G')
		return 1;
	if (c == 'R')
		return 2;
	throw;
}

const int N = 205;
char str[N];
bool _used[N][N][N];
bool ans[3];

struct State
{
	int cnt[3];
	State() : cnt() {}

	bool & used()
	{
		return _used[cnt[0] ][cnt[1] ][cnt[2] ];
	}
	void dfs()
	{
		if (used() ) return;
		used() = true;

		for (int i = 0; i < 3; i++)
			if (cnt[i] >= 2)
			{
				State nx = *this;
				nx.cnt[i]--;
				nx.dfs();
			}
		for (int i = 0; i < 3; i++)
		{
			int a = (i + 1) % 3;
			int b = (i + 2) % 3;
			
			if (cnt[a] == 0 && cnt[b] == 0 && cnt[i] == 1)
			{
				ans[i] = true;
			}

			if (cnt[a] > 0 && cnt[b] > 0)
			{
				State nx = *this;
				nx.cnt[a]--;
				nx.cnt[b]--;
				nx.cnt[i]++;
				nx.dfs();
			}
		}
	}
} S;


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	scanf("%s", str);

	for (int i = 0; i < n; i++)
		S.cnt[getId(str[i] ) ]++;
	S.dfs();

	for (int i = 0; i < 3; i++)
		if (ans[i] )
			printf("%c", answer[i] );
	printf("\n");

	return 0;
}