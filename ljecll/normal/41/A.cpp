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
//	freopen ("cf041a.in", "r", stdin);
//	freopen ("cf041a.out", "w", stdout);
	cin >> a >> b;
	if (a.length() != b.length())
	{
		printf("NO\n");
		return 0;
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[a.length() - i - 1])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}