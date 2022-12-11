/*
PROG: cf467b
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

#define MAXM 1001

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, long long> pil;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;

int N, M, K;
int arr[MAXM];
int val;
int ans;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf467b.in", "r"))
	{	
		freopen ("cf467b.in", "r", stdin);
		freopen ("cf467b.out", "w", stdout);
	}
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}
	cin >> val;
	for (int i = 0; i < M; i++)
	{
		if ((__builtin_popcount(arr[i] ^ val)) <= K)
		{
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}