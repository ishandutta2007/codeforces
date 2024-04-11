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

const int N = 105;
char str[N];

string readS()
{
	scanf("%s", str);
	return string(str);
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d", &n);
	string home = readS();

	int cntOut = 0;
	for (int i = 0; i < n; i++)
	{
		string x = readS();
		string a = x.substr(0, 3);
		string b = x.substr(5, 3);
//		eprintf("%s\n", b.c_str() );
		if (a == home)
			cntOut++;
		if (b == home)
			cntOut--;
	}
	if (cntOut)
		printf("contest\n");
	else
		printf("home\n");


	return 0;
}