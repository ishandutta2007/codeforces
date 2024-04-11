/*
PROG: cf711a
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

#define MAXN 1001

using namespace std;

int N;
string s[MAXN];
bool win = false;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf711a.in", "r"))
	{	
		freopen ("cf711a.in", "r", stdin);
		freopen ("cf711a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (s[i][j]== 'O' && s[i][j + 1] == 'O')
			{
				s[i][j] = '+';
				s[i][j + 1] = '+';
				win = true;
				break;
			}
		}
		if (win)
		{
			break;
		}
	}
	if (!win)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < N; i++)
	{
		cout << s[i] << '\n';
	}
}