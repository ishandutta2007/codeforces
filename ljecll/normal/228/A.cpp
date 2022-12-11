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

int arr[4];
map<int, bool> m;
int ans;

int main()
{
//	freopen ("cf228a.in", "r", stdin);
//	freopen ("cf228a.out", "w", stdout);
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &arr[i]);
		if (m[arr[i]])
		{
			ans++;
		}
		m[arr[i]] = true;
	}
	printf("%d\n", ans);
	return 0;

}