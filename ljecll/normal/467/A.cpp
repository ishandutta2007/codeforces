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

int N;
int ans;

int main()
{
//	freopen ("cf467a.in", "r", stdin);
//	freopen ("cf467a.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if ((b - a) >= 2)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}