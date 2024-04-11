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

const int N = (int)2e5;
const int IT = 150;

int n;
int64 T;
int64 p[N];
int64 t[N];
int rat_perm[N], p_perm[N];
int64 min_finish[N], max_finish[N];
double min_score[N], max_score[N];

bool rat_cmp(int a, int b)
{
	return t[a] * p[b] < t[b] * p[a];
}

bool p_cmp(int a, int b)
{
	return p[a] < p[b];
}

bool good(double c)
{
	for (int i = 0; i < n; i++)
	{
		min_score[i] = p[i] * (1 - c * (double)max_finish[i] / (double)T);
		max_score[i] = p[i] * (1 - c * (double)min_finish[i] / (double)T);
	}

	int b = 0;
	double max_pref = 0;

	for (int i = 0; i <= n; i++)
	{
		if (i == n || p[p_perm[b]] < p[p_perm[i]])
		{
			for (int j = b; j < i; j++)
			{
				if (min_score[p_perm[j]] < max_pref)
					return false;
			}

			for (int j = b; j < i; j++)
				max_pref = max(max_pref, max_score[p_perm[j]]);
			b = i;
		}
	}
	return true;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &p[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &t[i]);

	for (int i = 0; i < n; i++)
		T += t[i];

	for (int i = 0; i < n; i++)
	{
		rat_perm[i] = i;
		p_perm[i] = i;
	}
	sort(rat_perm, rat_perm + n, rat_cmp);
	sort(p_perm, p_perm + n, p_cmp);

	int b = 0;
	int64 sum = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == n || rat_cmp(rat_perm[b], rat_perm[i]))
		{
			//[b, i)
			for (int j = b; j < i; j++)
				min_finish[rat_perm[j]] = sum + t[rat_perm[j]];
			for (int j = b; j < i; j++)
				sum += t[rat_perm[j]];
			for (int j = b; j < i; j++)
				max_finish[rat_perm[j]] = sum;
			b = i;
		}
	}

	double l = 0;
	double r = 1;
	for (int it = 0; it < IT; it++)
	{
		double c = (l + r) / 2;
		if (good(c))
			l = c;
		else
			r = c;
	}

	printf("%.10lf\n", l);
	
	return 0;
}