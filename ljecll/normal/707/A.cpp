/*
PROG: cf707a
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

int N, M;
char c;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf707a.in", "r"))
	{	
		freopen ("cf707a.in", "r", stdin);
		freopen ("cf707a.out", "w", stdout);
	}
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			if (c != 'B' && c != 'W' && c != 'G')
			{
				cout << "#Color\n";
				return 0;
			}
		}
	}
	cout << "#Black&White\n";
	return 0;
}