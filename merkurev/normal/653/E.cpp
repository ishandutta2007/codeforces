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

void imp()
{
	printf("impossible\n");
	exit(0);
}

const int N = (int) 3e5 + 100;

set <pair <int, int> > s;
vector <int> comp[N];
vector <int> ids, nids;
int liesIn[N];
bool removed[N];

void merge(int a, int b)
{
	if ((int) comp[a].size() < (int) comp[b].size() )
		swap(a, b);

	removed[b] = true;
	for (int x : comp[b] )
	{
		liesIn[x] = a;
		comp[a].push_back(x);
	}
	comp[b].clear();
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int deg0 = n - 1;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		if (a > b)
			swap(a, b);
		s.insert(make_pair(a, b) );
		s.insert(make_pair(b, a) );
		if (a == 0)
			deg0--;
	}
	if (deg0 < k)
		imp();
	for (int i = 0; i < n; i++)
	{
		liesIn[i] = i;
		comp[i].push_back(i);
		ids.push_back(i);
	}
	for (int v = n - 1; v >= 0; v--)
	{
		if (v == 0 && (int) ids.size() > k + 1)
			imp();

		for (int j = 0; j < (int) ids.size(); j++)
		{
			int cid = ids[j];
			if (cid == liesIn[v] || removed[cid] ) continue;
			bool fnd = false;
			for (int x : comp[cid] )
			{
				if (x == 0 || s.count(make_pair(v, x) ) != 0) continue;
				merge(liesIn[v], cid);
				fnd = true;
				break;
			}
			if (!fnd)
				nids.push_back(cid);
		}
		nids.push_back(liesIn[v] );
		ids = nids;
		nids.clear();
	
		if (v == 0 && (int) ids.size() != 1) 
			imp();
	}


	printf("possible\n");
	return 0;
}