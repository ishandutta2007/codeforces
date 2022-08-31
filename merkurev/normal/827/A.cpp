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

const int N = (int) 2e6 + 100;
char s[N], p[N];
set <int> pos;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	int len = 0;
	for (int it = 0; it < n; it++)
	{
		scanf("%s", p);
		int plen = strlen(p);
		int k;
		scanf("%d", &k);
		for (int iq = 0; iq < k; iq++)
		{
			int x;
			scanf("%d", &x);
			x--;
			while (len < x + plen)
			{
				pos.insert(len);
				len++;
			}
			while (true)
			{
				auto iter = pos.lower_bound(x);
				if (iter == pos.end() ) break;
				int id = *iter;
				if (id - x >= plen) break;
				s[id] = p[id - x];
				pos.erase(iter);
			}
		}
	}

	for (int i = 0; i < len; i++)
		if (s[i] == 0)
			s[i] = 'a';
	printf("%s\n", s);

	return 0;
}