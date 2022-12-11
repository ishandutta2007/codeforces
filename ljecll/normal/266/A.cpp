#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <complex>
#define MAXN 55

using namespace std;

char s[MAXN];
string x;
unsigned N;
unsigned i;

int main()
{
//	freopen ("cf266a.in", "r", stdin);
//	freopen ("cf266a.out", "w", stdout);
	scanf("%u %s", &N, &s);
	x += s[0];
	for (unsigned j = 1; j < N; j++)
	{
		if (s[j] != s[i])
		{
			x += s[j];
			i = j;
		}
	}
	printf("%u\n", N - x.size());

}