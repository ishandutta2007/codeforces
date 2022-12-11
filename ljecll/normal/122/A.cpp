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

int N;

bool lucky(int x)
{
	stringstream ss;
	ss << x;
	string a = ss.str();
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != '4' && a[i] != '7')
		{
			return false;
		}
	}
	return true;
}

int main()
{
//	freopen ("cf122a.in", "r", stdin);
//	freopen ("cf122a.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		if (N % i)
		{
			continue;
		}
		if (lucky(i))
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}