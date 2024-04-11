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

const int N = (int)3e5;

int n, k, q;
int t[N];

bool cmp(int a, int b)
{
	if (t[a] != t[b])
		return t[a] > t[b];
	return a < b;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d%d%d", &n, &k, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	
	set<int, decltype(&cmp)> s(&cmp);
	for (int ii = 0; ii < q; ii++)
	{
		int type, id;
		scanf("%d%d", &type, &id);
		id--;

		if (type == 1)
		{
			s.insert(id);
		}
		else
		{
			bool found = false;
			auto it = s.begin();
			for (int i = 0; i < k; i++)
			{
				if (it == s.end())
					break;
				if ((*it) == id)
					found = true;
				it++;
			}

			printf("%s\n", found ? "YES" : "NO");
		}
	}

	return 0;
}