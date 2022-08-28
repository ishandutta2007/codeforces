#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define debug_flag true
#else
	#define debug_flag false
#endif

#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
    string name = it -> substr((*it)[0] == ' ', it -> length());
    if (isalpha(name[0]))
	    cerr << name  << " = " << a << " ";
	else
	    cerr << name << " ";
	_print(++it, args...);
}

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42;
#endif

typedef long long int int64;
typedef double mdouble;

const int N = (int) 2e5 + 100;
//const int K = 55;
int tt[N];

mdouble Tsum[N];
mdouble RTsum[N];

int n, k;

mdouble dp[N], _dp[N];
mdouble INF = 1e30;

int stX[N];
int stStart[N];
int stSz;

mdouble getVal(int id, int pos)
{
	return dp[id] + (Tsum[pos] - Tsum[id] ) * (RTsum[n] - RTsum[pos] );
}

mdouble solve()
{
	k = min(n, k);
	
	for (int i = 0; i < N; i++)
		dp[i] = -INF;
	dp[0] = 0;

	for (int it = 0; it < k; it++)
	{
//		for (int i = 0; i <= n; i++)
//			eprintf("%.5lf ", dp[i] );
//		eprintf("\n");

		stSz = 0;
		for (int i = it; i < n; i++)
		{
			while (stSz > 0 && stStart[stSz - 1] >= i && getVal(stX[stSz - 1], stStart[stSz - 1] ) <= getVal(i, stStart[stSz - 1] ) )
				stSz--;
			if (stSz == 0)
			{
				stX[stSz] = i;
				stStart[stSz] = i;
				stSz++;
				continue;
			}
			int l = min(i - 1, stStart[stSz - 1] ), r = n + 1;
			while (r - l > 1)
			{
				int m = (l + r) / 2;
				if (getVal(stX[stSz - 1], m) <= getVal(i, m) )
					r = m;
				else
					l = m;
			}
			if (r < n + 1)
			{
				stX[stSz] = i;
				stStart[stSz] = r;
				stSz++;
			}
		}
		int pos = 0;
		for (int i = it + 1; i <= n; i++)
		{
			if (pos != stSz - 1 && stStart[pos + 1] == i)
				pos++;
			_dp[i] = getVal(stX[pos], i);
		}
		for (int i  = it + 1; i <= n; i++)
			dp[i] = _dp[i];
	}
	return dp[n];
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &tt[i] );

	for (int i = 0; i < n; i++)
	{
		Tsum[i + 1] = Tsum[i] + tt[i];
		RTsum[i + 1] = RTsum[i] + (mdouble) 1. / (mdouble) tt[i];
	}

	mdouble answer = 0;
	for (int i = 0; i < n; i++)
		answer += (Tsum[i + 1] - Tsum[0] ) / (mdouble) tt[i];

	mdouble ans = solve();
//	eprintf("answer = %.5lf, ans = %.5lf\n", answer, ans);

	printf("%.10lf\n", (double) (answer - ans) );

	return 0;
}