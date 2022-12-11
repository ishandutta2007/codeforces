/*
PROG: cf509a
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
#define MAXN 100

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, long long> pil;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;

int N;
int grid[MAXN][MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf509a.in", "r"))
	{	
		freopen ("cf509a.in", "r", stdin);
		freopen ("cf509a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		grid[0][i] = 1;
		grid[i][0] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
		}
	}
	cout << grid[N - 1][N - 1] << '\n';
	return 0;
}