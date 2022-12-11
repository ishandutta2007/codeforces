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
int n;

//lucky digits are 4 and 7
bool lucky(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != '4' && a[i] != '7')
		{
			return false;
		}
	}
	return true;
}

int main()
{
//	freopen ("cf110a.in", "r", stdin);
//	freopen ("cf110a.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '4' || s[i] == '7')
		{
			n++;
		}
	}
	stringstream ss;
	ss << n;
	string x = ss.str();
	if (lucky(x))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}