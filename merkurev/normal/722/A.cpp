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


char s[10], t[10];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int h;
	scanf("%d", &h);
	scanf("%s", s);

	vector <pair <int, int> > v;
	for (int i = 0; i < h; i++)
	{
		int x = i;
		if (h == 12 && x == 0) x = 12;
		for (int j = 0; j < 60; j++)
			v.push_back(make_pair(x, j));
	}
	int ans = 10;
	string answer = "";
	for (auto p : v)
	{
		sprintf(t, "%02d:%02d", p.first, p.second);
		int cur = 0;
		for (int i = 0; i < 5; i++)
			if (s[i] != t[i] )
				cur++;
		if (cur < ans)
		{
			ans = cur;
			answer = string(t);
		}
	}
	printf("%s\n", answer.c_str() );



	return 0;
}