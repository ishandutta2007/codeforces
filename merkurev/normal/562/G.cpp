#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
using namespace std;

typedef long long int int64;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int N = (int)1e5;

int n;
vector<pair<pair<int, int>, int> > tuples[N];
int size[N];
set<int> good_id;

bool is_good(int x)
{
	return tuples[x].size() != 0 && size[x] < 9;
}

void check(int x)
{
	if (is_good(x))
		good_id.insert(x);
	else
		good_id.erase(x);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 0; i < 4 * n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		c--;
		tuples[a].push_back({{b, c}, i});
	}

	for (int i = 0; i < n; i++)
	{
		size[i] = 8;	
	}
	for (int i = 0; i < n; i++)
	{
		check(i);
	}

	vector<int> ans;
	for (int it = 0; it < 4 * n; it++)
	{
		assert(!good_id.empty());
		
		int id = *good_id.begin();
		good_id.erase(id);

		auto t = tuples[id].back();
		auto p = t.first;
		tuples[id].pop_back();

		ans.push_back(t.second);

		size[p.first]--;
		size[p.second]--;
		size[id]++;

		check(p.first);
		check(p.second);
		check(id);
	}
	reverse(ans.begin(), ans.end() );

	printf("YES\n");
	for (int i = 0; i < 4 * n; i++)
		printf("%d ", ans[i] + 1);

	return 0;
}