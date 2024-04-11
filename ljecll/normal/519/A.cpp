/*
PROG: cf519a
LANG: C++
 */
#include <cstdlib>
#include <csignal>
#include <csetjmp>
#include <cstdarg>
#include <typeinfo>
#include <bitset>
#include <functional>
#include <utility>
#include <ctime>
#include <cstddef>
#include <new>
#include <memory>
#include <climits>
#include <cfloat>
#include <limits>
#include <exception>
#include <cassert>
#include <cerrno>
#include <cctype>
#include <cwctype>
#include <cstring>
#include <cwchar>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>
#include <valarray>
#include <numeric>
#include <iosfwd>
#include <ios>	
#include <istream>	
#include <ostream>
#include <iostream>
#include <fstream>	
#include <strstream>	
#include <iomanip>	
#include <streambuf>
#include <cstdio>
#include <locale>	
#include <clocale>

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000001
#define LLINF 1000000000000000001ll
#define EPS 0.000000000000001
#define PI ((4.0) * atan(1.0))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, long long> pil;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;

map<char, int> m;
int net;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf519a.in", "r"))
	{	
		freopen ("cf519a.in", "r", stdin);
		freopen ("cf519a.out", "w", stdout);
	}
	m['Q'] = 9;
	m['R'] = 5;
	m['N'] = 3;
	m['B'] = 3;
	m['P'] = 1;
	m['q'] = -9;
	m['r'] = -5;
	m['n'] = -3;
	m['b'] = -3;
	m['p'] = -1;
	for (int i = 0; i < 8; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++)
		{
			net += m[s[j]];
		}
	}
	if (net < 0)
	{
		cout << "Black\n";
	}
	if (net == 0)
	{
		cout << "Draw\n";
	}
	if (net > 0)
	{
		cout << "White\n";
	}
	return 0;
}