/*
PROG: cf677a
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

#define MAXN 1001

using namespace std;

int N, H;
int height[MAXN];
int ans;

int main()
{
	if (fopen("cf677a.in", "r"))
	{	
		freopen ("cf677a.in", "r", stdin);
		freopen ("cf677a.out", "w", stdout);
	}
	cin >> N >> H;
	for (int i = 0; i < N; i++)
	{
		cin >> height[i];
		if (height[i] > H)
		{
			ans += 2;
		}
		else
		{
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}