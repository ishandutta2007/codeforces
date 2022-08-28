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

void rename(vector<int> &l, vector<int> n)
{
	for (int i = 0; i < (int)l.size(); i++)
		l[i] = n[l[i]];
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);

	vector<bool> used(n + 1);
	used[a] = used[b] = used[c] = used[d] = true;

	if (n == 4 || k < n + 1)
	{
		printf("-1\n");
		return 0;
	}

	vector<int> path1;
	path1.push_back(a);
	path1.push_back(c);
	for (int i = 1; i <= n; i++)
		if (!used[i])
			path1.push_back(i);
	path1.push_back(d);
	path1.push_back(b);

	vector<int> path2;
	path2.push_back(c);
	path2.push_back(a);
	for (int i = 1; i <= n; i++)
		if (!used[i])
			path2.push_back(i);
	path2.push_back(b);
	path2.push_back(d);

	for (int x : path1)
		printf("%d ", x);
	printf("\n");

	for (int x : path2)
		printf("%d ", x);
	printf("\n");

	return 0;
}