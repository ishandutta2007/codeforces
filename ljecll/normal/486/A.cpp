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

using namespace std;

long long N;

int main()
{
//	freopen ("cf486a.in", "r", stdin);
//	freopen ("cf486a.out", "w", stdout);
	scanf("%I64d", &N);
	if (N % 2)
	{
		printf("%I64d\n", ((-1 * N - 1)/2));
	}
	else
	{
		printf("%I64d\n", (N/2));
	}
	return 0;
}