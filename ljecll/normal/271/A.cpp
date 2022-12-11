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

bool dist(int x)
{
	stringstream ss;
	ss << x;
	string s = ss.str();
	bool distd[15];
	for (int i = 0; i < 10; i++)
	{
		distd[i] = false;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (distd[s[i] - '0'])
		{
			return false;
		}
		distd[s[i] - '0'] = true;
	}
	return true;
}
int main()
{
//	freopen ("cf271a.in", "r", stdin);
//	freopen ("cf271a.out", "w", stdout);
	scanf("%d", &N);
	N++;
	while(!dist(N))
	{
		N++;
//		cerr << N << endl;
	}
	printf("%d\n", N);
	return 0;
}