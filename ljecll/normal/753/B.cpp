/*
PROG: cf753b
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

int no[10];
vector<int> v;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf753b.in", "r"))
	{	
		freopen ("cf753b.in", "r", stdin);
		freopen ("cf753b.out", "w", stdout);
	}
	for (int i = 0; i < 10; i++)
	{
		int res;
		for (int j = 0; j < 4; j++)
		{
			cout << i;
		}
		cout << '\n';
		fflush(stdout);
		int a, b;
		cin >> a >> b;
		no[i] = a + b;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < no[i]; j++)
		{
			v.PB(i);
		}
	}
	do
	{
		for (int i = 0; i < 4; i++)
		{
			cout << v[i];
		}
		cout << '\n';
		fflush(stdout);
		int junk;
		cin >> junk >> junk;
	}
	while (next_permutation(v.begin(), v.end()));
	return 0;
}