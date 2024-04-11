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

int main()
{
//	freopen ("cf263a.in", "r", stdin);
//	freopen ("cf263a.out", "w", stdout);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int n;
			cin >> n;
			if (n)
			{
				printf("%d\n", abs(2 - j) + abs(2 - i));
			}
		}
	}
	return 0;
}