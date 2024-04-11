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

string a, b;

int main()
{
//	freopen ("cf112a.in", "r", stdin);
//	freopen ("cf112a.out", "w", stdout);
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
	{
		if (isupper(a[i]))
		{
			a[i] += 'a' - 'A';
		}
		if (isupper(b[i]))
		{
			b[i] += 'a' - 'A';
		}
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] < b[i])
		{
			printf("-1\n");
			return 0;
		}
		else if (a[i] > b[i])
		{
			printf("1\n");
			return 0;
		}
	}
	printf("0\n");
	return 0;
}