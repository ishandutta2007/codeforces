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
#define MAXN 30

using namespace std;

bool seen[MAXN];
string s;
int dist;

int main()
{
//	freopen ("cf236a.in", "r", stdin);
//	freopen ("cf236a.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (!seen[s[i] - 'a'])
		{
			dist++;
			seen[s[i] - 'a'] = true;
		}
		dist %= 2;
	}
	if (dist % 2)
	{
		printf("IGNORE HIM!\n");
	}
	else
	{
		printf("CHAT WITH HER!\n");
	}
	return 0;
}