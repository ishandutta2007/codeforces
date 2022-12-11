/*
PROG: cf149a
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

#define MAXN 12

using namespace std;

int K;
int arr[MAXN];
int tsum;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf149a.in", "r"))
	{	
		freopen ("cf149a.in", "r", stdin);
		freopen ("cf149a.out", "w", stdout);
	}
	cin >> K;
	if (K == 0)
	{
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < 12; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + 12);
	for (int i = 11; i >= 0; i--)
	{
		tsum += arr[i];
		if (tsum >= K)
		{
			cout << 12 - i << '\n';
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}