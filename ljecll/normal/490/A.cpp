/*
PROG: cf490a
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
#define MAXN 4

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, long long> pil;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;

int N;
vector<int> v[3];
int ans;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf490a.in", "r"))
	{	
		freopen ("cf490a.in", "r", stdin);
		freopen ("cf490a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		a--;
		v[a].PB(i);
	}
	ans = min(v[0].size(), min(v[1].size(), v[2].size()));
	cout << ans << '\n';
	for (int i = 0; i < ans; i++)
	{
		cout << v[0][i] + 1 << ' ' << v[1][i] + 1 << ' ' << v[2][i] + 1 << '\n';
	}
	return 0;
}