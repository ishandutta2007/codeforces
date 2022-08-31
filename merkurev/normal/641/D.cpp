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
const int N = (int) 1e5 + 100;
long double M[N], m[N];
long double p[N], q[N];

const long double eps = 1e-7;
bool eq(long double x, long double y)
{
	return abs(x - y) < eps;
}
bool ls(long double x, long double y)
{
	return x < y && !eq(x, y);
}

int par[N][2];

void test(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ls(p[i], 0) || ls(q[i], 0) ) throw;
		long double cm = p[i] * q[i], cM = p[i] * q[i];
		for (int j = 0; j < i; j++)
			cM += p[i] * q[j] + q[i] * p[j];
		for (int j = i + 1; j < n; j++)
			cm += p[i] * q[j] + q[i] * p[j];
		if (!eq(cm, m[i] ) || !eq(cM, M[i] ) )
		{
			eprintf("%.10Lf %.10Lf\n", cm, m[i] );
			eprintf("%.10Lf %.10Lf\n", cM, M[i] );
			throw;
		}
	}
}

long double read_double()
{
	double a;
	scanf("%lf", &a);
	return a;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		M[i] = read_double();
		//scanf("%Lf", &M[i] );
	}
	for (int i = 0; i < n; i++)
	{
		//scanf("%Lf", &m[i] );
		m[i] = read_double();
	}
	
	long double sM = 0, sm = 0;
	for (int i = 0; i < n; i++)
	{
		sM += M[i];
		sm += m[i];
		long double A = -1.;
		long double B = sM + sm;
		long double C = -sM;
		long double D = (B * B - 4. * A * C);
//		if (ls(D, 0) ) throw;
		if (D < 0) D = 0;
		D = sqrt(D);
		double X1 = (-B + D) / (2. * A);
//		double X2 = (-B - D) / (2. * A);		
		p[i] = X1;
//		p[i][1] = X2;
		q[i] = sM + sm - p[i];
//		q[i][1] = sM + sm - p[i][1];
//		eprintf("%.5Lf %.5Lf\n", p[i][0], q[i][0] );
//		eprintf("%.5Lf %.5Lf\n", p[i][1], q[i][1] );
//		eprintf("\n");
	}
	for (int i = n - 1; i > 0; i--)
	{
		p[i] -= p[i - 1];
		q[i] -= q[i - 1];
	}

//	test(n);

	for (int i = 0; i < n; i++)
		printf("%.10lf ", (double)p[i] );
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%.10lf ", (double)q[i] );
	printf("\n");

	return 0;
}