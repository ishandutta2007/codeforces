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

string a, b;
string ans;

int main()
{
//	freopen ("cf061a.in", "r", stdin);
//	freopen ("cf061a.out", "w", stdout);
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i])
		{
			ans += '0';
		}
		else
		{
			ans += '1';
		}
	}
	cout << ans << '\n';
	return 0;
}