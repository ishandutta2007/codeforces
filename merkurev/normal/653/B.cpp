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

int n;
vector<pair<string, string> > all_trans;
int ans;
map<string, bool> dp;

bool can(string str)
{
	if (str == "a")
		return true;
	if ((int)str.length() == 1)
		return false;
	if (dp.count(str) == 1)
		return dp[str];
	bool res = false;
	for (auto p : all_trans)
	{
		if (str.substr(0, 2) != p.first)
			continue;
		string new_str = p.second + str.substr(2);
		if (can(new_str))
		{
			res = true;
			break;
		}
	}

	return dp[str] = res;
}

void rec(string str)
{
	if ((int)str.length() == n)
	{
		ans += can(str);
		return;
	}

	for (int c = 'a'; c <= 'f'; c++)
	{
		str.push_back(c);
		rec(str);
		str.pop_back();
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int q;
	scanf("%d%d", &n, &q);
	all_trans.resize(q);
	for (int i = 0; i < q; i++)
		cin >> all_trans[i].first >> all_trans[i].second;
	
	rec("");

	printf("%d\n", ans);

	return 0;
}