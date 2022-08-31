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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 1e5 + 100;
char str[N];
map <string, int> m;
vector <pair <int, string> > v;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		m[string(str) ] = i;
	}
	for (auto p : m)
		v.push_back(make_pair(p.second, p.first) );
	sort(v.begin(), v.end() );
	reverse(v.begin(), v.end() );
	for (auto p : v)
		printf("%s\n", p.second.c_str() );

	return 0;
}