/*
PROG: cf734a
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

#define INF 1000000001
#define LLINF 1000000000000000001ll
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;

int N;
string s;
int A, D;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf734a.in", "r"))
	{	
		freopen ("cf734a.in", "r", stdin);
		freopen ("cf734a.out", "w", stdout);
	}
	cin >> N >> s;
	for (int i = 0; i < N; i++)
	{
		if (s[i] == 'A')
		{
			A++;
		}
		else
		{
			D++;
		}
	}
	if (A == D)
	{
		cout << "Friendship\n";
	}
	if (A > D)
	{
		cout << "Anton\n";
	}
	if (D > A)
	{
		cout << "Danik\n";
	}
	return 0;
}