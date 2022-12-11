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
int ans;
bool seen[262];

int main()
{
//	freopen ("cf443a.in", "r", stdin);
//	freopen ("cf443a.out", "w", stdout);
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]) && !seen[s[i]])
		{
			ans++;
			seen[s[i]] = true;
		}
	}
	printf("%d\n", ans);
	return 0;
}