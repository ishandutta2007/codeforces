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
typedef long double mdouble;

const int N = (int) 5e5 + 100;
const int K = 70;
int type[N], xxx[N];
int par[N];

mdouble probLess[N][K];


void reCalc(int v)
{
//	eprintf("add child %d to %d\n", v, par[v] );
	int d = 0;
	for (int i = 1; i < K; i++)
		probLess[v][i] = 1.;
	mdouble oldProb = 1., nold;
	while (par[v] != -1 && d + 1 < K)
	{
		nold = (probLess[par[v] ][d + 1] + 1.) / 2.;
		probLess[par[v] ][d + 1] *= (probLess[v][d] + 1.) / 2. / oldProb;
//		eprintf("probLess(%d, %d) : %.10lf -> %.10lf\n", par[v], d + 1, (double) nold, (double) probLess[par[v] ][d + 1] );
		oldProb = nold;
		v = par[v];
		d++;
	}
}

mdouble getAns(int v)
{
//	eprintf("ask at %d\n", v);
	mdouble ans = 0;
	for (int i = 1; i < K; i++)
		ans += 1. - probLess[v][i];
	return ans;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int q;
	scanf("%d", &q);
//	q = (int) 5e5;
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &type[i], &xxx[i] );
		xxx[i]--;
//		type[i] = 1;
//		xxx[i] = i + 1;
	}

	par[0] = -1;
	reCalc(0);
	int sz = 1;
	for (int i = 0; i < q; i++)
	{
		int v = xxx[i];
		if (type[i] == 1)
		{
			par[sz] = v;
			reCalc(sz);
			sz++;
		}
		else
		{
			mdouble ans = getAns(v);
			printf("%.10lf\n", (double) ans);
		}
	}


	return 0;
}