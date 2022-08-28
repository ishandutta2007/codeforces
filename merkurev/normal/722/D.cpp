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


const int N = 50500;
const int SZ = N * 60;

int tree[SZ][2];
int sz = 1;
bool term[SZ];
int val[SZ];

vector <int> ans;

int dfs(int v, int m)
{
	int x = 0;
	if (term[v] ) x++;
	if (tree[v][0] != 0)
		x += dfs(tree[v][0], m);
	if (tree[v][1] != 0)
		x += dfs(tree[v][1], m);
	if (x != 0 && val[v] <= m)
	{
		ans.push_back(val[v]);
		x--;
	}
	return x;
}

bool test(int m)
{
	ans.clear();
	return dfs(0, m) == 0;
}

void addWord(vector <int> v)
{
	int pos = 0;
	for (int x : v)
	{
		if (tree[pos][x] == 0)
		{
			val[sz] = val[pos] * 2 + x;
			tree[pos][x] = sz++;
		}
		pos = tree[pos][x];
	}
	term[pos] = true;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	val[0] = 1;
	int n;
	scanf("%d", &n);
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		mx = max(mx, x);
		vector <int> v;
		while (x > 1)
		{
			v.push_back(x & 1);
			x >>= 1;
		}
		reverse(v.begin(), v.end() );
		addWord(v);
	}
	int l = 0, r = mx;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (test(m))
			r = m;
		else
			l = m;
	}
	test(r);
	for (int x : ans)
		printf("%d ", x);
	printf("\n");

	return 0;
}