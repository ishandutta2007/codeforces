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
string ans;

int main()
{
//	freopen ("cf118a.in", "r", stdin);
//	freopen ("cf118a.out", "w", stdout);
	cin >> s;
	for (unsigned i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
		{
			s[i] += ('a' - 'A');
		}
//		cout << s[i];
	}
	for (unsigned i = 0; i < s.length(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
		{
			continue;
		}
		ans += '.';
		ans += s[i];
	}
	cout << ans << '\n';
	return 0;
}