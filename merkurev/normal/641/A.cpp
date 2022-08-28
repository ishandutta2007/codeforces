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

	int n;
	scanf("%d", &n);
	vector<int> sign(n);
	for (int i = 0; i < n; i++)
	{
		char c;
		scanf(" %c", &c);
		sign[i] = (c == '>' ? 1 : -1);
	}
	vector<int> dist(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &dist[i]);
	
	vector<bool> used(n);
	int cur = 0;
	while (true)
	{
		if (cur < 0 || cur >= n)
		{
			printf("FINITE\n");
			return 0;
		}
		if (used[cur])
		{
			printf("INFINITE\n");
			return 0;
		}
		used[cur] = true;
		cur += sign[cur] * dist[cur];
	}

	assert(false);

	return 0;
}