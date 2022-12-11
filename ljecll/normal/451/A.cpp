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

int a, b;

int main()
{
//	freopen ("cf451a.in", "r", stdin);
//	freopen ("cf451a.out", "w", stdout);
	scanf("%d %d", &a, &b);
	if (min(a,b) % 2)
	{
		printf("Akshat\n");
	}
	else
	{
		printf("Malvika\n");
	}
	return 0;
}