/*
PROG: cf716a
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

int N, C;
int pre, cur;
int ans;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf716a.in", "r"))
	{	
		freopen ("cf716a.in", "r", stdin);
		freopen ("cf716a.out", "w", stdout);
	}
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> cur;
		if (i != 0 && cur - pre > C)
		{
			ans = 0;
		}
		ans++;
		pre = cur;
	}
	cout << ans << '\n';
	return 0;
}