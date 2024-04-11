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
//	freopen ("cf133a.in", "r", stdin);
//	freopen ("cf133a.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;

}