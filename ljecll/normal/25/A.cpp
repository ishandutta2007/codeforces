/*
PROG: cf52a
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

#define MAXN 101

using namespace std;

int N;
int arr[MAXN];
int od, ev;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf52a.in", "r"))
	{	
		freopen ("cf52a.in", "r", stdin);
		freopen ("cf52a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] % 2)
		{
			od++;
		}
		else
		{
			ev++;
		}
	}
	if (od > ev)
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[i] % 2 == 0)
			{
				cout << i + 1 << '\n';
				return 0;
			}
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[i] % 2)
			{
				cout << i + 1 << '\n';
				return 0;
			}
		}
	}
	return 0;
}