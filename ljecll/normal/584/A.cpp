/*
PROG: cf584a
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

ll N, M;
int m[11];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf584a.in", "r"))
	{	
		freopen ("cf584a.in", "r", stdin);
		freopen ("cf584a.out", "w", stdout);
	}
	cin >> M >> N;
	if (M == 1 && N == 10)
	{
		cout << "-1\n";
		return 0;
	}
	if (N == 10)
	{
		for (int i = 1; i < M; i++)
		{
			cout << 6;
		}
		cout << "0\n";
		return 0;
	}
	if (M == 1)
	{
		cout << N << '\n';
		return 0;
	}
	m[1] = 10;
	m[2] = 10;
	m[3] = 69;
	m[4] = 44;
	m[5] = 55;
	m[6] = 42;
	m[7] = 21;
	m[8] = 88;
	m[9] = 81;
	cout << m[N];
	for (int i = 2; i < M; i++)
	{
		cout << "0";
	}
	cout << '\n';
	return 0;
}