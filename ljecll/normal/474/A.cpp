/*
PROG: cf474a
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

char c;
string s;
map<char, char> m;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf474a.in", "r"))
	{	
		freopen ("cf474a.in", "r", stdin);
		freopen ("cf474a.out", "w", stdout);
	}
	cin >> c;
	if (c == 'L')
	{
		s = "qwertyuiop";
		for (int i = 0; i < s.length() - 1; i++)
		{
			m[s[i]] = s[i + 1];
		}
		s = "asdfghjkl;";
		for (int i = 0; i < s.length() - 1; i++)
		{
			m[s[i]] = s[i + 1];
		}
		s = "zxcvbnm,./";
		for (int i = 0; i < s.length() - 1; i++)
		{
			m[s[i]] = s[i + 1];
		}
	}
	else
	{
		s = "qwertyuiop";
		for (int i = 0; i < s.length() - 1; i++)
		{
			m[s[i + 1]] = s[i];
		}
		s = "asdfghjkl;";
		for (int i = 0; i < s.length() - 1; i++)
		{
			m[s[i + 1]] = s[i];
		}
		s = "zxcvbnm,./";
		for (int i = 0; i < s.length() - 1; i++)
		{
			m[s[i + 1]] = s[i];
		}
	}
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		cout << m[s[i]];
	}
	cout << '\n';
	return 0;
}