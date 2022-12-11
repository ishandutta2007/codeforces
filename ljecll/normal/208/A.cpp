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

char s[300];

int main()
{
	//	freopen ("cf208a.in", "r", stdin);
	//	freopen ("cf208a.out", "w", stdout);
	cin >> s;
	if (strlen(s) <= 3)
	{
		cout << s << '\n';
		return 0;
	}
	for (int i = 0; i < strlen(s) - 2; i++)
	{
		if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
		{
			s[i] = ' ';
			s[i + 1] = ' ';
			s[i + 2] = ' ';
		}
	}
	cout << s << '\n';
	return 0;
}