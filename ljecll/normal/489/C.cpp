/*
PROG: cf489c
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

int N, S;
int n, s;
string small, big;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf489c.in", "r"))
	{	
		freopen ("cf489c.in", "r", stdin);
		freopen ("cf489c.out", "w", stdout);
	}
	cin >> N >> S;
	if (N == 1 && S == 0)
	{
		cout << "0 0\n";
		return 0;
	}
	if (S < 1 || S > 9 * N)
	{
		cout << "-1 -1\n";
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		small += '0';
		big += '0';
	}
	s = S;
	if (S >= 9 * (N - 1) + 2)
	{
		small[0] = '0' + (S - 9 * (N - 1));
		for (int i = 1; i < N; i++)
		{
			small[i] = '9';
		}
	}
	else
	{
		small[0] = '1';
		s--;
		for (int i = N - 1; i > 0; i--)
		{
			small[i] = '0' + min(9, s);
			s -= min(9, s);
		}
	}
	s = S;
	for (int i = 0; i < N; i++)
	{
		big[i] = '0' + min(9, s);
		s -= min(9, s);
	}
	cout << small << ' ' << big << '\n';
	return 0;
	//for smallest, you wanna get as many 10000000000___-
}