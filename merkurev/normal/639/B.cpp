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

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int n, d, h;
	scanf("%d%d%d", &n, &d, &h);

	if (n == 2)
	{
		assert(h == 1 && d == 1);
		printf("1 2\n");
		return 0;
	}

	if (d > 2 * h || d == 1)
	{
		printf("-1\n");
		return 0;
	}
	
	if (h == d)
	{
		for (int i = 2; i <= d + 1; i++)
			printf("%d %d\n", i - 1, i);
		for (int i = d + 2; i <= n; i++)
			printf("2 %d\n", i);
		return 0;
	}

	int f = min(d, h);
	int s = d - f;

	if (s == 0)
	{
		f--;
		s++;
	}

	dbg(f, s);

	for (int i = 0; i < f; i++)
		printf("%d %d\n", i + 1, i + 2);
	printf("1 %d\n", f + 2);
	for (int i = f + 3; i <= f + s + 1; i++)
		printf("%d %d\n", i - 1, i);
	for (int i = f + s + 2; i <= n; i++)
		printf("1 %d\n", i);

	return 0;
}