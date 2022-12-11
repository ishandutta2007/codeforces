/*
PROG: cf1a
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

#define MAXN 100001
#define MP make_pair

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf1a.in", "r"))
	{	
		freopen ("cf1a.in", "r", stdin);
		freopen ("cf1a.out", "w", stdout);
	}
	long long n, m, a;
	cin >> n >> m >> a;
	if (n%a==0)
	{
		if (m%a==0)
		{
			cout << (n*m)/(a*a) << '\n';
		}
		else
			cout << (n/a)*((m/a)+1) << '\n';
	}
	else
	{
		if (m%a==0)
		{
			cout << ((n/a)+1)*(m/a) << '\n';
		}
		else
		{
			cout << ((n/a)+1)*((m/a)+1) << '\n';
		}
	}
	return 0;
}