/*
PROG: cf520a
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

using namespace std;

int N;
string s;
bool seen[256];

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf520a.in", "r"))
	{	
		freopen ("cf520a.in", "r", stdin);
		freopen ("cf520a.out", "w", stdout);
	}
	cin >> N >> s;
	for (int i = 0; i < N; i++)
	{
		s[i] = toupper(s[i]);
		seen[s[i]] = true;
	}
	for (char c = 'A'; c <= 'Z'; c++)
	{
		if (seen[c] == false)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}