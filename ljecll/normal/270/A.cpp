/*
PROG: cf270a
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

#define MAXN 24

using namespace std;

int N;
int arr[MAXN] = {3, 4, 5, 6, 8, 9, 10, 12, 15, 18, 20, 24, 30, 36, 40, 45, 60, 72, 90, 120, 180, 360};
bool reg[181];

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf270a.in", "r"))
	{	
		freopen ("cf270a.in", "r", stdin);
		freopen ("cf270a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < 22; i++)
	{
		int z = arr[i];
		reg[(z - 2)*180/z] = true;
	}
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (reg[x])
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}