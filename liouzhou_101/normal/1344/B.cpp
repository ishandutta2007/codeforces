#include <bits/stdc++.h>

using namespace std;

//using ll = int64_t;
using ll = long long;
using ull = uint64_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = double;

#define X first
#define Y second

#ifndef ONLINE_JUDGE
#define FWRITE
#endif

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
		char ch = getchar();
		if (ch == EOF) return 0;
		for (; !isdigit(ch); )
		{
			ch = getchar();
			if (ch == EOF) return 0;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
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
		char ch = getchar();
		if (ch == EOF) return 0;
		for (; !isdigit(ch); )
		{
			ch = getchar();
			if (ch == EOF) return 0;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
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

	void write(char* s)
	{
		for (; *s; ++s) putchar(*s);
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

template<class T>
void print(const T& a)
{
	for (auto x : a) printf("%d ", x); puts("");
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

const ll B = 31;
//const ll MOD = 998244353;
const int INF = 1000000010;
const ll INFll = 1000000000000000000LL;
const int MAXN = 1010;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

ld det(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

int n, m;
char s[MAXN][MAXN];
vector<int> vx[MAXN], vy[MAXN];

bool check()
{
	int fx = 0, fy = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vx[i].empty())
		{
			fx = 1;
			continue;
		}
		sort(vx[i].begin(), vx[i].end());
		int sz = vx[i].size();
		if (vx[i].back() - vx[i].front() + 1 == sz) continue;
		return false;
	}
	for (int j = 0; j < m; ++j)
	{
		if (vy[j].empty())
		{
			fy = 1;
			continue;
		}
		sort(vy[j].begin(), vy[j].end());
		int sz = vy[j].size();
		if (vy[j].back() - vy[j].front() + 1 == sz) continue;
		return false;
	}
	if (fx != fy) return false;
	return true;
}

void solve()
{
	/*
	n = inp();
	m = inp();
	*/
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		//read(s[i]);
		scanf("%s", s[i]);
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cnt += s[i][j] == '#';
	if (cnt == 0)
	{
		writeln(0);
		return;
	}

	if (n == 1 || m == 1)
	{
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cnt += s[i][j] == '#';
		if (cnt != n * m && cnt != 0)
		{
			writeln(-1);
			return;
		}
		if (cnt == 0)
			writeln(0);
		else
			writeln(1);
		return;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == '#')
			{
				vx[i].push_back(j);
				vy[j].push_back(i);
			}
		}
	if (!check())
	{
		writeln(-1);
		return;
	}
	int res = 0;
	vector<vector<int>> u(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (u[i][j]) continue;
			if (s[i][j] != '#') continue;
			res++;
			queue<pii> q;
			q.push({ i,j });
			u[i][j] = 1;
			while (!q.empty())
			{
				auto [x, y] = q.front();
				q.pop();
				for (int k = 0; k < 4; ++k)
				{
					int tx = x + dx[k], ty = y + dy[k];
					if (0 <= tx && tx < n && 0 <= ty && ty < m && s[tx][ty] == '#' && !u[tx][ty])
					{
						u[tx][ty] = 1;
						q.push({ tx,ty });
					}
				}
			}
		}
	writeln(res);
}

int main()
{

	//for (int T = inp(); T --; )
	solve();

	return 0;
}