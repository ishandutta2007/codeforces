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

int st[2], nst[2];

int Mod(int x, int n)
{
	return (x % n + n) % n;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int n, q;
	scanf("%d%d", &n, &q);
	st[0] = 0;
	st[1] = 1;
	
	for (int i = 0; i < q; i++)
	{
		int t, x;
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d", &x);
			if (x % 2 == 0)
			{
				nst[0] = Mod(st[0] - x, n);
				nst[1] = Mod(st[1] - x, n);
			}
			else
			{
				nst[0] = Mod(st[1] - x - 1, n);
				nst[1] = Mod(st[0] - x + 1, n);
			}
			st[0] = nst[0];
			st[1] = nst[1];
		}
		else
		{
			swap(st[0], st[1] );
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i & 1)
			printf("%d ", Mod(st[1] + i - 1, n) + 1);
		else
			printf("%d ", Mod(st[0] + i, n) + 1);
	}
	printf("\n");

	return 0;
}