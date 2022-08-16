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

//mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rd(1);

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

//const ll B = 31;
//const ll MOD = 1000000007;
const int INF = 1000000010;
const ll INFll = 4000000000000000000LL;
const int MAXN = 600010;
const int MAXK = 20;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

ld det(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

struct directed_graph
{
	int n;
	vector<vector<int>> v;

	directed_graph(int n = 0)
	{
		init(n);
	}
	void init(int n)
	{
		assert(n >= 0);
		this->n = n;
		v = vector<vector<int>>(n + 1);
	}
	void addedge(int x, int y)
	{
		assert(1 <= x && x <= n);
		assert(1 <= y && y <= n);
		v[x].push_back(y);
	}
	void erase_multiedges()
	{
		for (int i = 1; i <= n; ++i)
		{
			sort(v[i].begin(), v[i].end());
			v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
		}
	}

	vector<int> in_degree()
	{
		vector<int> ret(n + 1);
		for (int x = 1; x <= n; ++x)
			for (auto y : v[x])
				ret[y] ++;
		return ret;
	}
	vector<int> topsort()
	{
		vector<int> deg = in_degree();
		vector<int> ret;
		queue<int> q;
		for (int i = 1; i <= n; ++i)
			if (!deg[i]) q.push(i);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			ret.push_back(x);
			for (auto y : v[x])
				if (!--deg[y]) q.push(y);
		}
		return ret;
	}

	int times;
	vector<int> dfn, low, in;
	vector<int> st;
	int scc;
	vector<int> belong;
	void tarjan(int x)
	{
		dfn[x] = low[x] = ++times;
		st.push_back(x);
		in[x] = 1;
		for (auto y : v[x])
		{
			if (!dfn[y])
			{
				tarjan(y);
				freshmin(low[x], low[y]);
			}
			else if (in[y])
				freshmin(low[x], dfn[y]);
		}
		if (dfn[x] == low[x])
		{
			scc++;
			while (1)
			{
				int y = st.back();
				st.pop_back();
				in[y] = 0;
				belong[y] = scc;
				if (x == y) break;
			}
		}
	}
	directed_graph strong_connected_component()
	{
		times = 0;
		dfn = vector<int>(n + 1);
		low = vector<int>(n + 1);
		in = vector<int>(n + 1);
		st = vector<int>();
		scc = 0;
		belong = vector<int>(n + 1);
		for (int i = 1; i <= n; ++i)
			if (!dfn[i]) tarjan(i);
		directed_graph ret(scc);
		for (int x = 1; x <= n; ++x)
			for (auto y : v[x]) if (belong[x] != belong[y])
				ret.addedge(belong[x], belong[y]);
		// ret.erase_multiedges();
		return ret;
	}
};

struct two_sat
{
	int n;
	vector<pii> e;

	two_sat(int n = 0)
	{
		init(n);
	}
	void init(int n)
	{
		assert(n >= 0);
		this->n = n;
		e = vector<pii>();
	}
	// if (x=a) then (y=b).
	void add(int x, int a, int y, int b)
	{
		assert(1 <= x && x <= n);
		assert(0 <= a && a <= 1);
		assert(1 <= y && y <= n);
		assert(0 <= b && b <= 1);
		e.push_back({ x + a * n, y + b * n });
		if (x != y) e.push_back({ y + (1 - b) * n, x + (1 - a) * n });
	}
	void choose(int x)
	{
		assert(1 <= x && x <= n);
		add(x, 0, x, 1);
	}
	void never_choose(int x)
	{
		assert(1 <= x && x <= n);
		add(x, 1, x, 0);
	}

	// return a possible assignment
	pair<bool, vector<int>> solve()
	{
		directed_graph G(n + n);
		for (auto p : e)
		{
			int x = p.X, y = p.Y;
			G.addedge(x, y);
		}
		directed_graph H = G.strong_connected_component();
		vector<int> rev(n + n + 1);
		for (int i = 1; i <= n; ++i)
		{
			if (G.belong[i] == G.belong[i + n]) return { false, {} };
			rev[G.belong[i]] = G.belong[i + n];
			rev[G.belong[i + n]] = G.belong[i];
		}
		int scc = H.n;
		queue<int> q;
		vector<int> deg = H.in_degree();
		for (int i = 1; i <= scc; ++i)
			if (!deg[i]) q.push(i);
		vector<int> used(scc + 1);
		vector<int> choose(scc + 1), notchoose(scc + 1);
		for (int i = 1; i <= n; ++i)
		{
			choose[G.belong[i + n]]++;
			notchoose[G.belong[i]]++;
		}
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			if (!used[x])
			{
				if (choose[x] < notchoose[x])
				{
					used[x] = 1;
					used[rev[x]] = 2;
				}
				else
				{
					used[x] = 2;
					used[rev[x]] = 1;
				}
			}
			for (auto y : H.v[x])
				if (!--deg[y]) q.push(y);
		}
		vector<int> ret(n + 1);
		for (int i = 1; i <= n; ++i)
			ret[i] = used[G.belong[i]] == 2;
		return { true, ret };
	}
};


void solve()
{
	int n;
	read(n);
	vector<int> a(n), b(n);
	input(a);
	input(b);

	vector<vector<pii>> v(n + 1);
	for (int i = 0; i < n; ++i)
		v[a[i]].push_back({ i + 1, 0 });
	for (int i = 0; i < n; ++i)
		v[b[i]].push_back({ i + 1, 1 });
	two_sat T(n);
	for (int i = 1; i <= n; ++i)
	{
		if (v[i].size() != 2)
		{
			return writeln(-1);
		}
		auto [apos, atag] = v[i][0];
		auto [bpos, btag] = v[i][1];
		if (atag != btag)
		{
			T.add(apos, 0, bpos, 0);
			T.add(apos, 1, bpos, 1);
		}
		else
		{
			T.add(apos, 0, bpos, 1);
			T.add(apos, 1, bpos, 0);
		}
	}
	auto [flag, res] = T.solve();
	if (!flag)
	{
		return writeln(-1);
	}
	vector<int> ans;
	for (int i = 1; i <= n; ++i) if (res[i]) ans.push_back(i);
	writeln<int>(ans.size());
	print(ans);
}

int main()
{

	int T = 1;
	read(T);
	for (int test = 1; test <= T; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}

	return 0;
}