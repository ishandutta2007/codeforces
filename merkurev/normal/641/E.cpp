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

const int N = (int)1e6 + 100;
const int B = 2 * N;

int bptr;
int buf[B];

int* get_arr(int size)
{
	bptr += size;
	assert(bptr <= B);
	return buf + bptr - size;
}

struct Fenwick
{
	int size;
	int* a;

	Fenwick(int _size = 0)
	{
		size = _size;
		a = get_arr(size);
	}

	void add(int pos, int val)
	{
		for (int i = pos; i < size; i |= (i + 1))
			a[i] += val;
	}

	int get(int pos)
	{
		int res = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
			res += a[i];
		return res;
	}
};


int q;
int A[N], T[N], X[N];

int x_cnt;
int x_list[N];

int cnt[N];
int head[N], cur_head[N];
int super_list[N];

Fenwick fen[N];

void compress()
{
	x_cnt = 0;
	for (int i = 0; i < q; i++)
		x_list[x_cnt++] = X[i];
	sort(x_list, x_list + x_cnt);
	x_cnt = unique(x_list, x_list + x_cnt) - x_list;
	for (int i = 0; i < q; i++)
		X[i] = lower_bound(x_list, x_list + x_cnt, X[i]) - x_list;

	for (int i = 0; i < q; i++)
		cnt[X[i]]++;
	
	for (int i = 1; i < N; i++)
		cur_head[i] = head[i] = head[i - 1] + cnt[i - 1];
	
	for (int i = 0; i < q; i++)
		super_list[cur_head[X[i]]++] = T[i];
	
	for (int i = 0; i < N; i++)
	{
		int l = head[i];
		int r = head[i] + cnt[i];
		sort(super_list + l, super_list + r);
		cnt[i] = unique(super_list + l, super_list + r) - (super_list + l);
	}

	for (int i = 0; i < q; i++)
		T[i] = lower_bound(super_list + head[X[i]], super_list + head[X[i]] + cnt[X[i]], T[i]) - (super_list + head[X[i]]);

	for (int i = 0; i < N; i++)
		fen[i] = Fenwick(cnt[i]);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d", &q);
	for (int i = 0; i < q; i++)
		scanf("%d%d%d", &A[i], &T[i], &X[i]);

	compress();

	for (int i = 0; i < q; i++)
	{
		int type = A[i];
		int t = T[i];
		int x = X[i];
		if (type == 1)
		{
			fen[x].add(t, 1);
		}
		else if (type == 2)
		{
			fen[x].add(t, -1);
		}
		else
		{
			int ans = fen[x].get(t);
			printf("%d\n", ans);
		}
	}
		
	return 0;
}