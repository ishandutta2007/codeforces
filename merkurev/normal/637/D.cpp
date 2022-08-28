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

typedef long long int int64;

const int RUN = 0;
const int JUMP = 1;

string to_str(int code)
{
	if (code == RUN)
		return "RUN";
	if (code == JUMP)
		return "JUMP";
	throw;
}

void fail()
{
	printf("IMPOSSIBLE\n");
	exit(0);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int n, m, s, d;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	a.push_back(-1);
	sort(a.begin(), a.end());

	int start_from = -1;
	int fuel = 1;
	vector<pair<int, int> > ans;

	for (int i = 1; i < (int)a.size(); i++)
	{
		if (fuel <= 0)
			fail();

		int xl = a[i - 1];
		int xr = a[i];
		int len = xr - xl;

		int new_fuel1 = fuel - len;
		int new_fuel2 = -1;
		if (s + 2 <= len)
			new_fuel2 = d - 1;

		if (new_fuel1 > new_fuel2)
			fuel = new_fuel1;
		else
		{
			ans.emplace_back(JUMP, xl + 1 - start_from);
			int new_start_from = xr - 1;
			ans.emplace_back(RUN, new_start_from - (xl + 1));
			start_from = new_start_from;
			fuel = new_fuel2;
		}
	}

	if (fuel <= 0)
		fail();

	ans.emplace_back(JUMP, a.back() + 1 - start_from);
	ans.emplace_back(RUN, m - (a.back() + 1));

	for (int i = 1; i < (int)ans.size(); i++)
		if (ans[i].second != 0)
			printf("%s %d\n", to_str(ans[i].first).c_str(), ans[i].second);

	return 0;
}