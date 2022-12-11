/*
PROG: cf702a
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

#define MAXN 100001

using namespace std;

int N;
int arr[MAXN];
int cnt;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf702a.in", "r"))
	{	
		freopen ("cf702a.in", "r", stdin);
		freopen ("cf702a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		if (i == 0 || arr[i] > arr[i - 1])
		{
			cnt++;
		}
		else
		{
			cnt = 1;
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}