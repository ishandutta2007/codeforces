/*
PROG: cf723a
LANG: C++
debug my code
*/
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
#include <iomanip>

#define INF 1000000001
#define LLINF 1000000000000000001

using namespace std;

int a, b, c;
int bestloc, bestdist = INF;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf723a.in", "r"))
	{	
		freopen ("cf723a.in", "r", stdin);
		freopen ("cf723a.out", "w", stdout);
	}
	cin >> a >> b >> c;
	for (int i = 0; i <= 100; i++)
	{
		int tdist = 0;
		tdist = abs(i - a) + abs(i - b) + abs(i - c);
		if (tdist < bestdist)
		{
			bestdist = tdist;
			bestloc = i;
		}
	}
	cout << bestdist << endl;
}