/*
PROG: cf478a
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

using namespace std;

int a, b, c, d, e;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf478a.in", "r"))
	{	
		freopen ("cf478a.in", "r", stdin);
		freopen ("cf478a.out", "w", stdout);
	}
	cin >> a >> b >> c >> d >> e;
	if ((a + b + c + d + e) % 5 || a + b + c + d + e == 0)
	{
		cout << "-1\n";
	}
	else
	{
		cout << (a + b + c + d + e) / 5 << '\n';
	}
	return 0;
}