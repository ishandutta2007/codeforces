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

int ans;
int N;
string s1, s2;

int main()
{
//	freopen ("cf344a.in", "r", stdin);
//	freopen ("cf344a.out", "w", stdout);
	cin >> N >> s1;
	ans++;
	for (int i = 1; i < N; i++)
	{
		cin >> s2;
		if (s1 != s2)
		{
			ans++;
		}
		s1 = s2;
	}
	cout << ans << '\n';
	return 0;
}