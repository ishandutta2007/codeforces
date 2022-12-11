/*
PROG: cf313a
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
#define A first 
#define B second

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

string s;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf313a.in", "r"))
	{	
		freopen ("cf313a.in", "r", stdin);
		freopen ("cf313a.out", "w", stdout);
	}
	cin >> s;
	if (s[0] != '-')
	{
		cout << s << '\n';
		return 0;
	}
	else
	{
		if (s.length() == 3)
		{
			if (min(s[2], s[1]) == '0')
			{
				cout << "0\n";
				return 0;
			}
			else
			{
				cout << "-" << min(s[2], s[1]) << '\n';
				return 0;
			}
		}
		string t = s;
		t.pop_back();
		string w = s;
		w.pop_back();
		w.pop_back();
		w += s[s.length() - 1];
		cout << min(t, w) << '\n';
		return 0;
	}
}