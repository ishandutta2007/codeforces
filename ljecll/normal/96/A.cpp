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

string s;
bool dangerous(int a)
{
	char pos = s[a];
	for (int i = a - 6; i < a; i++)
	{
		if (s[i] != pos)
		{
			return false;
		}
	}
	return true;
}

int main()
{
//	freopen ("cf96a.in", "r", stdin);
//	freopen ("cf96a.out", "w", stdout);
	cin >> s;
	if (s.length() < 7)
	{
		printf("NO\n");
		return 0;
	}
	for (int i = 6; i < s.length(); i++)
	{
		if (dangerous(i))
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}