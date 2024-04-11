/*
PROG: cf514a
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

string s;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf514a.in", "r"))
	{	
		freopen ("cf514a.in", "r", stdin);
		freopen ("cf514a.out", "w", stdout);
	}
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] <= '4' || (i == 0 && s[i] == '9'))
		{
			cout << s[i];
			continue;
		}
		if (s[i] == '5')
		{
			cout << 4;
		}
		if (s[i] == '6')
		{
			cout << 3;
		}
		if (s[i] == '7')
		{
			cout << 2;
		}
		if (s[i] == '8')
		{
			cout << 1;
		}
		if (s[i] == '9')
		{
			cout << 0;
		}
	}
	cout << '\n';

}