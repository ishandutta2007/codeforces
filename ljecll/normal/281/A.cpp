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
//	freopen ("cf281a.in", "r", stdin);
//	freopen ("cf281a.out", "w", stdout);
	cin >> s;
	if (!isupper(s[0]))
	{
		s[0] += ('A' - 'a');
	}
	cout << s << '\n';
	return 0;
}