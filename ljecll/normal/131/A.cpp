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

int main()
{
//	freopen ("cf131a.in", "r", stdin);
//	freopen ("cf131a.out", "w", stdout);
	cin >> s;
	for (int i = 1; i < s.length(); i++)
	{
		if (!isupper(s[i]))
		{
			cout << s << '\n';
			return 0;
		}
	}
	if (isupper(s[0]))
	{
		s[0] += ('a' - 'A');
	}
	else
	{
		s[0] += ('A' - 'a');
	}
	for (int i = 1; i < s.length(); i++)
	{
		s[i] += ('a' - 'A');
	}
	cout << s << '\n';
	return 0;
}