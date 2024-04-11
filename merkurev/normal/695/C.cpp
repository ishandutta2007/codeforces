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

struct Point
{
	int64 x, y;
	Point() : x(), y() {}
	Point(int64 _x, int64 _y) : x(_x), y(_y) {}
	void scan()
	{
		scanf("%lld%lld", &x, &y);
	}
	Point operator + (const Point &p) const
	{
		return Point(x + p.x, y + p.y);
	}
	Point operator - (const Point &p) const
	{
		return Point(x - p.x, y - p.y);
	}
	int64 operator % (const Point &p) const
	{
		return x * p.x + y * p.y;
	}
	int64 operator * (const Point &p) const
	{
		return x * p.y - y * p.x;
	}
	bool on_line(const Point &A, const Point &B) const
	{
		return (A - *this) * (B - *this) == 0;
	}
	bool on_seg(const Point &A, const Point &B) const
	{
		return on_line(A, B) && (A - *this) % (B - *this) <= 0;
	}
	int64 length2() const
	{
		return *this % *this;
	}
	int64 dist_to2(const Point &p) const
	{
		return (*this - p).length2();
	}
};

const int N = 1005;
const int K = 8;

int k, n;
Point A[K];
Point M[N];
vector<int> from_m[N][K];

Point null_point;

int matched[K];
int ql, qr;
int q[N];
bool in_q[N];

int on_seg_cnt[K];
int m_on_it[N];

bool on_seg[N][N][K];


bool cmp(int a, int b)
{
	return null_point.dist_to2(M[a]) < null_point.dist_to2(M[b]);
}

bool solve(int need_m)
{
	vector<int> perm(k);
	for (int i = 0; i < k; i++)
		perm[i] = i;
	
	do
	{
		ql = qr = 0;
		fill(matched, matched + K, -1);
		fill(on_seg_cnt, on_seg_cnt + K, 0);

		q[qr++] = need_m;
		in_q[need_m] = true;
		for (int a : perm)
		{
			if (qr > k)
				break;
			if (ql == qr)
				break;
			int m = q[ql++];
			matched[a] = m;
			for (int next_m : from_m[m][a])
			{
				if (qr > k)
					break;
				if (!in_q[next_m])
				{
					in_q[next_m] = true;
					q[qr++] = next_m;
				}
			}
		}
		
		//?
		for (int i = 0; i <= qr; i++)
			in_q[q[i]] = false;

		if (qr > k || ql != qr)
			continue;
	
		int used_m = 0;
		for (int a = 0; a < k; a++)
		{
			if (matched[a] != -1)
				m_on_it[used_m++] = matched[a];
		}

		for (int a = 0; a < k; a++)
		{
			int m = matched[a];
			if (m == -1)
				continue;
			for (int i = 0; i < used_m; i++)
			{
				int next_m = m_on_it[i];
				if (on_seg[next_m][m][a])
					on_seg_cnt[a]++;
			}
		}

		bool fail = false;
		for (int it = 0; it < used_m && !fail; it++)
		{
			bool flag = false;
			for (int a = 0; a < k && !flag; a++)
			{
				int m = matched[a];
				if (m == -1 || on_seg_cnt[a] != 1)
					continue;
				matched[a] = -1;
				for (int next_a = 0; next_a < k; next_a++)
				{
					int next_m = matched[next_a];
					if (next_m == -1)
						continue;
					if (on_seg[m][next_m][next_a])
						on_seg_cnt[next_a]--;
				}
				flag = true;
				break;
			}
			if (!flag)
				fail = true;
		}
		
		if (!fail)
			return true;

	} while (next_permutation(perm.begin(), perm.end()));
	
	return false;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d%d", &k, &n);
	for (int i = 0; i < k; i++)
		A[i].scan();
	for (int i = 0; i < n; i++)
		M[i].scan();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int t = 0; t < k; t++)
				on_seg[i][j][t] = M[i].on_seg(M[j], A[t]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			vector<int> all;
			for (int t = 0; t < n && (int)all.size() <= K; t++)
				if (M[t].on_seg(M[i], A[j]))
					all.push_back(t);
			null_point = M[i];
			sort(all.begin(), all.end(), cmp);
			from_m[i][j] = all;
		}
	}

	for (int x : from_m[1][2])
		dbg(x);

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (solve(i))
		{
			dbg(i);
			ans++;
		}
	printf("%d\n", ans);

	return 0;
}