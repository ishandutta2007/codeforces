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

int N, ans;

int main()
{
//	freopen ("cf231a.in", "r", stdin);
//	freopen ("cf231a.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		bool a, b, c;
		cin >> a >> b >> c;
		if (a && b || c && b || a && c)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}