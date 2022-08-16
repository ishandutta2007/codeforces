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
using ld = double;

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
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rd(1);

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
//const int INF = 1000000010;
//const ll INFll = 4000000000000000000LL;
//const int MAXN = 600010;
//const int MAXK = 21;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

template<class T>
T det(T x1, T y1, T x2, T y2, T x3, T y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

template<class T>
T dis(T x1, T y1, T x2, T y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

static const int MAXN = 40010; // number of nodes in AC automaton
static const int MAXM = 2; // cardinal of alphabet

int tot;

struct node
{
	node* next[MAXM];
	node* fail;
	int val;
};

node tree[MAXN];
node* root;

node* new_node()
{
	node* it = &tree[++tot];
	for (int i = 0; i < MAXM; ++i) it->next[i] = 0;
	it->fail = 0;
	it->val = 0;
	return it;
}

void init()
{
	tot = 0;
	root = new_node();
}

node* add(const vector<int>& s)
{
	node* it = root;
	for (auto c : s)
	{
		int x = c;
		if (!it->next[x]) it->next[x] = new_node();
		it = it->next[x];
	}
	it->val = 1;
	//printf("%x\n", it);
	return it;
}

void build()
{
	root->fail = root;
	queue<node*> Q;
	for (int i = 0; i < MAXM; ++i)
		if (root->next[i])
		{
			root->next[i]->fail = root;
			Q.push(root->next[i]);
		}
		else
			root->next[i] = root;
	while (!Q.empty())
	{
		node* it = Q.front();
		Q.pop();
		for (int i = 0; i < MAXM; ++i)
		{
			if (!it->next[i])
				it->next[i] = it->fail->next[i];
			else
			{
				it->next[i]->fail = it->fail->next[i];
				it->next[i]->val |= it->next[i]->fail->val;
				Q.push(it->next[i]);
			}
		}
	}
}

const ull INFull = 1ULL << 63;

ull f[111][55][55];

void solve()
{
	int G, N, M;
	read(G, N, M);
	vector<vector<vector<int>>> v(G);
	for (int i = 0; i < N; ++i)
	{
		int a, k;
		read(a, k);
		vector<int> b(k);
		input(b);
		v[a].push_back(b);
	}
	init();
	for (int i = 0; i < M; ++i)
	{
		int k;
		read(k);
		vector<int> b(k);
		input(b);
		add(b);
	}
	build();
	for (int a = 0; a < G; ++a)
		for (int x = 1; x <= tot; ++x)
			for (int y = 1; y <= tot; ++y)
				f[a][x][y] = INFull;
	for (int a = 0; a < 2; ++a)
		for (int x = 1; x <= tot; ++x) if (!tree[x].val && !tree[x].next[a]->val)
			f[a][x][tree[x].next[a] - tree] = 1;
	
	ll time_stamp = clock();
	while (1)
	{
		int flag = 0;

		for (int a = 0; a < G; ++a)
		{
			for (const auto& b : v[a])
			{
				static ull g[55][55], tmp[55][55];
				for (int x = 1; x <= tot; ++x)
					for (int y = 1; y <= tot; ++y) g[x][y] = INFull;
				for (int x = 1; x <= tot; ++x) if (!tree[x].val) g[x][x] = 0;

				for (const auto& c : b)
				{
					for (int x = 1; x <= tot; ++x)
						for (int y = 1; y <= tot; ++y) tmp[x][y] = g[x][y], g[x][y] = INFull;
					for (int x = 1; x <= tot; ++x) if (!tree[x].val)
						for (int y = 1; y <= tot; ++y) if (!tree[y].val && tmp[x][y] < INFull)
							for (int z = 1; z <= tot; ++z) if (!tree[z].val && f[c][y][z] < INFull)
							{
								if (g[x][z] > tmp[x][y] + f[c][y][z])
								{
									g[x][z] = tmp[x][y] + f[c][y][z];
								}
							}
				}

				for (int x = 1; x <= tot; ++x)
					for (int y = 1; y <= tot; ++y)
						if (f[a][x][y] > g[x][y])
						{
							flag = 1;
							f[a][x][y] = g[x][y];
						}
			}
		}

		if (flag == 0) break;
		if (clock() - time_stamp > 720000) break;
	}

	for (int a = 2; a < G; ++a)
	{
		ull res = INFull;
		for (int y = 1; y <= tot; ++y)
			if (f[a][1][y] < res)
			{
				res = f[a][1][y];
			}
		if (res == INFull)
			writeln("YES");
		else
			writeln("NO ", ll(res));
	}
}

int main()
{

	int T = 1;
	//read(T);
	//init();
	for (int test = 1; test <= T; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}

	return 0;
}