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
string s1;
int j = 0;

int main()
{
//	freopen ("cf058a.in", "r", stdin);
//	freopen ("cf058a.out", "w", stdout);
	cin >> s;
	bool h = false;
	//clearly the h and o are the last o ne because XD
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'h' || h)
		{
			h = true;
			s1 += s[i];
		}
	}
	if (s1.size() == 0)
	{
		printf("NO\n");
		return 0;
	}
	for (int i = s1.length() - 1; i >= 0; i--)
	{
		if (s1[i] != 'o')
		{
			s1.erase(s1.begin() + i);
		}
		else
		{
			break;
		}
	}
	if (s1.size() == 0)
	{
		printf("NO\n");
		return 0;
	}
//	cout << s1 << endl;
	s1.erase(s1.begin());
	s1.erase(s1.end() - 1);
//	cout << s1 << endl;
	int epos = -1;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == 'e')
		{
			epos = i;
			break;
		}
	}
	if (epos == -1)
	{
		printf("NO\n");
		return 0;
	}
	int noell = 0;
	for (int i = epos + 1; i < s1.length(); i++)
	{
		if (s1[i] == 'l')
		{
			noell++;
		}
		if (noell == 2)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}