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

const int N = 5005;
int n;
int list[N];
int ans[N];
int cnt[N];
int cur_ans;

void clear()
{
	cur_ans = 0;
	for (int i = 0; i < N; i++)
		cnt[i] = 0;
}

void add(int c)
{
	cnt[c]++;
	if (cnt[c] > cnt[cur_ans] || (cnt[c] == cnt[cur_ans] && c < cur_ans))
		cur_ans = c;
	ans[cur_ans]++;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);

	for (int i = 0; i < n; i++)
	{
		clear();
		for (int j = i; j < n; j++)
			add(list[j]);
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);

	return 0;
}