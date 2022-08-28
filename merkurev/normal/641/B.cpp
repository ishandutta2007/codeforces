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

const int N = 105;
int n, m, q;
pair<int, int> mx[N][N];
int mx_val[N][N];

void do_row(int r)
{
	auto tmp = mx[r][0];
	for (int i = 1; i < m; i++)
		mx[r][i - 1] = mx[r][i];
	mx[r][m - 1] = tmp;
}

void do_col(int c)
{
	auto tmp = mx[0][c];
	for (int i = 1; i < n; i++)
		mx[i - 1][c] = mx[i][c];
	mx[n - 1][c] = tmp;
}

void do_set(int r, int c, int val)
{
	auto p = mx[r][c];
	mx_val[p.first][p.second] = val;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d%d%d", &n, &m, &q);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mx[i][j] = make_pair(i, j);

	for (int it = 0; it < q; it++)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int r;
			scanf("%d", &r);
			r--;
			do_row(r);
		}
		else if (type == 2)
		{
			int c;
			scanf("%d", &c);
			c--;
			do_col(c);
		}
		else
		{
			int r, c, val;
			scanf("%d%d%d", &r, &c, &val);
			r--;
			c--;
			do_set(r, c, val);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", mx_val[i][j]);
		printf("\n");
	}

	return 0;
}