#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
//using ll = long long;
using ull = uint64_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;

#define X first
#define Y second

//#ifndef ONLINE_JUDGE
#define FWRITE
//#endif

namespace io
{

#ifndef FWRITE
#include <unistd.h>
	auto unistd_read = read;
	auto unistd_write = write;
#endif
	const int BUFSIZE = 1 << 20;

	int isize, osize;
	char ibuf[BUFSIZE + 10], obuf[BUFSIZE + 10];
	char* is, * it, * os = obuf, * ot = obuf + BUFSIZE;

	char getchar()
	{
		if (is == it)
		{
			is = ibuf;
#ifdef FWRITE
			it = ibuf + fread(ibuf, 1, BUFSIZE, stdin);
#else
			it = ibuf + unistd_read(STDIN_FILENO, ibuf, BUFSIZE);
#endif
			if (is == it) return EOF;
		}
		return *is++;
	}

	char getalpha()
	{
		char c = getchar();
		while (!isalpha(c)) c = getchar();
		return c;
	}

	void putchar(char c)
	{
		*os++ = c;
		if (os == ot)
		{
#ifdef FWRITE
			fwrite(obuf, 1, BUFSIZE, stdout);
#else
			unistd_write(STDOUT_FILENO, obuf, BUFSIZE);
#endif
			os = obuf;
		}
	}

	int inp() {
		int x = 0, f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			if (ch == EOF) return -1;
			if (ch == '-') f = 1;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return f ? -x : x;
	}

	ll inp_ll() {
		ll x = 0; int f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
			if (ch == '-') f = 1;
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return f ? -x : x;
	}

	template<class T>
	bool read(T& x)
	{
		x = 0;
		int f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			if (ch == EOF) return 0;
			if (ch == '-') f = 1;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		if (f) x = -x;
		return 1;
	}

	bool read(char* s)
	{
		char* t = s;
		char ch = getchar();
		for (; ch == ' ' || ch == '\n'; ch = getchar());
		for (; ch != ' ' && ch != '\n' && ch != EOF; ch = getchar())
			*t++ = ch;
		*t = 0;
		return s != t;
	}

	template<class T, class... Args>
	bool read(T& x, Args&... args)
	{
		return read(x) && read(args...);
	}

	template<class T>
	bool readln(T& x)
	{
		x = 0;
		int f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			if (ch == EOF) return 0;
			if (ch == '-') f = 1;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		if (f) x = -x;
		for (; ch != '\n' && ch != EOF; ch = getchar());
		return 1;
	}

	bool readln(char* s)
	{
		char* t = s;
		while (1)
		{
			char ch = getchar();
			if (ch == '\n' || ch == EOF) break;
			*t++ = ch;
		}
		*t = 0;
		return s != t;
	}

	template<class T, class... Args>
	bool readln(T& x, Args&... args)
	{
		return read(x) && readln(args...);
	}

	template<class T>
	void write(T x)
	{
		static char s[22];
		static char* it = s + 20;
		static char* end = s + 20;

		if (x < 0)
		{
			putchar('-');
			x = -x;
		}

		do
		{
			*--it = x % 10 + '0';
			x /= 10;
		} while (x);
		/*
		if (!x)
			*-- it = '0';
		while (x)
		{
			*-- it = x%10+'0';
			x /= 10;
		}
		*/
		for (; it < end; ++it)
			putchar(*it);
	}

	void write(const char* s)
	{
		for (; *s; ++s) putchar(*s);
	}

	template<>
	void write(char* s)
	{
		write((const char*)s);
	}

	template<>
	void write(char c)
	{
		putchar(c);
	}

	template<class T, class... Args>
	void write(T x, Args... args)
	{
		write(x);
		write(args...);
	}

	void writeln()
	{
		putchar('\n');
	}

	template<class T, class... Args>
	void writeln(T x, Args... args)
	{
		write(x);
		writeln(args...);
	}

	template<class Iterator>
	bool input(Iterator st, Iterator ed)
	{
		for (; st != ed; ++st)
		{
			if (!read(*st)) return false;
		}
		return true;
	}

	template<class T>
	bool input(T& a)
	{
		return input(a.begin(), a.end());
	}

	template<class Iterator>
	void print(Iterator st, Iterator ed, const char* c = " ")
	{
		int flag = 0;
		for (; st != ed; ++st)
		{
			if (flag) write(c);
			flag = 1;
			write(*st);
		}
		writeln();
	}

	template<class T>
	void print(const T& a, const char* c = " ")
	{
		print(a.begin(), a.end(), c);
	}

	struct ender
	{
		~ender()
		{
			if (os != obuf)
#ifdef FWRITE
				fwrite(obuf, 1, os - obuf, stdout);
#else
				unistd_write(STDOUT_FILENO, obuf, os - obuf);
#endif
		}
	}__ender;

}

int64_t power(int64_t a, int64_t b, int64_t p)
{
	if (!b) return 1;
	int64_t t = power(a, b >> 1, p);
	t = t * t % p;
	if (b & 1) t = t * a % p;
	return t;
}

pll exgcd(ll a, ll b)
{
	if (b == 0) return { 1, 0 };
	//auto [x, y] = exgcd(b, a % b);
	auto e = exgcd(b, a % b);
	ll x = e.first;
	ll y = e.second;
	return { y, x - a / b * y };
}

//mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rd(678);

using namespace io;

template<class T>
inline void freshmin(T& a, const T& b)
{
	if (a > b) a = b;
}

template<class T>
inline void freshmax(T& a, const T& b)
{
	if (a < b) a = b;
}

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

template<class T>
T det(T x1, T y1, T x2, T y2, T x3, T y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}
/*
template<class T>
T dis(T x1, T y1, T x2, T y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
*/

void init()
{

}

void solve()
{
	int n;
	ll k;
	read(n, k);
	vector<vector<int>> v(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		read(x, y);
		x -= 1; y -= 1;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	vector<int> sz(n);
	vector<int> sub(n);
	function<void(int, int)> dfs = [&](int x, int pre)
	{
		sz[x] = 1;
		for (auto y : v[x])
		{
			if (y == pre) continue;
			dfs(y, x);
			freshmax(sub[x], sz[y]);
			sz[x] += sz[y];
		}
		freshmax(sub[x], n - sz[x]);
	};
	dfs(0, -1);
	int root = min_element(sub.begin(), sub.end()) - sub.begin();
	dfs(root, -1);

	ll low = 0, high = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i == root) continue;
		low += sz[i] % 2;
		high += sz[i];
	}
	if (!(low <= k && k <= high && low % 2 == k % 2))
		return writeln("NO");
	writeln("YES");
	
	vector<int> u(n), depth(n), pre(n), res(n);
	vector<vector<int>> candidates(n);
	vector<set<int>> contains(n);
	vector<set<int>> sons(n);
	for (auto son : v[root])
	{
		function<void(int)> dfs2 = [&](int x)
		{
			candidates[son].push_back(x);
			depth[x] = depth[pre[x]] + 1;
			for (auto y : v[x])
			{
				if (y == pre[x]) continue;
				pre[y] = x;
				sons[x].insert(y);
				dfs2(y);
			}
		};
		pre[son] = root;
		dfs2(son);
		contains[son] = set<int>(candidates[son].begin(), candidates[son].end());
		sort(candidates[son].begin(), candidates[son].end(), [&](int x, int y)
			{
				return depth[x] < depth[y];
			});
	}

	auto cmp = [&](int x, int y)
	{
		return contains[x].size() < contains[y].size();
	};
	vector<int> q = v[root];
	make_heap(q.begin(), q.end(), cmp);

	while (high != k)
	{
		int cur = q[0];
		pop_heap(q.begin(), q.end(), cmp);
		q.pop_back();
		while (!candidates[cur].empty())
		{
			int x = candidates[cur].back();
			if (sons[x].empty())
			{
				candidates[cur].pop_back();
			}
			else break;
		}
		if (int x = candidates[cur].back(); high - depth[x] * 2 > k)
		{
			high -= depth[x] * 2;
			if (sons[x].size() >= 2)
			{
				int a = *sons[x].begin();
				sons[x].erase(a);
				int b = *sons[x].begin();
				sons[x].erase(b);
				res[a] = b, res[b] = a;
				u[a] = u[b] = 1;
				contains[cur].erase(a);
				contains[cur].erase(b);
			}
			else
			{
				int a = *sons[x].begin();
				sons[x].erase(a);
				sons[pre[x]].erase(x);
				res[a] = x, res[x] = a;
				u[a] = u[x] = 1;
				candidates[cur].pop_back();
				contains[cur].erase(a);
				contains[cur].erase(x);
			}
			q.push_back(cur);
			push_heap(q.begin(), q.end(), cmp);
		}
		else
		{
			for (auto x : candidates[cur])
			{
				if (high - depth[x] * 2 == k && !sons[x].empty())
				{
					high -= depth[x] * 2;
					int a = *sons[x].begin();
					res[a] = x, res[x] = a;
					u[a] = u[x] = 1;
					break;
				}
			}
			break;
		}
	}

	assert(high == k);
	vector<int> r;
	function<void(int, int)> travel = [&](int x, int pre)
	{
		if (!u[x]) r.push_back(x);
		for (auto y : v[x])
		{
			if (y == pre) continue;
			travel(y, x);
		}
	};
	travel(root, -1);
	for (int i = 0; i < r.size() / 2; ++i)
	{
		res[r[i]] = r[i + r.size() / 2];
		res[r[i + r.size() / 2]] = r[i];
	}
	for (int i = 0; i < n; ++i)
		if (i < res[i]) writeln(i + 1, ' ', res[i] + 1);
}

int main()
{

	int T = 1;
	//read(T);
	init();
	for (int test = 1; test <= T; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}

	return 0;
}