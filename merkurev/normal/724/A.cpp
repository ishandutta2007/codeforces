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

string v[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	string as, bs;
	cin >> as >> bs;
	int a = find(v, v + 7, as) - v;
	int b = find(v, v + 7, bs) - v;
	if ((a + 31) % 7 == b || (a + 30) % 7 == b || (a + 28) % 7 == b)
		printf("YES\n");
	else
		printf("NO\n");



	return 0;
}