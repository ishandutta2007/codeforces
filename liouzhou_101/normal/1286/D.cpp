#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using ull = uint64_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using ld = double;

#define X first
#define Y second

#define FWRITE

namespace io
{

#ifndef FWRITE
#include <unistd.h>
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
			it = ibuf + read(STDIN_FILENO, ibuf, BUFSIZE);
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
			write(STDOUT_FILENO, obuf, BUFSIZE);
#endif
			os = obuf;
		}
	}

	int inp() {
		int x = 0, f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			//if (ch == EOF) return -1;
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

	template<>
	void write(const char* s)
	{
		for (; *s; ++s) putchar(*s);
	}

	template<>
	void write(char c)
	{
		putchar(c);
	}

	template<class T, class V>
	void write(T x, V y)
	{
		write(x);
		write(y);
	}

	template<class T>
	void writeln(T x)
	{
		write(x);
		putchar('\n');
	}

	struct ender
	{
		~ender()
		{
			if (os != obuf)
#ifdef FWRITE
				fwrite(obuf, 1, os - obuf, stdout);
#else
				write(STDOUT_FILENO, obuf, os - obuf);
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
	int64_t t = power(a, b>>1, p);
	t = t * t % p;
	if (b & 1) t = t * a % p;
	return t;
}

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

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

template<class data_type>
struct segment_tree
{
	using T = data_type;
	int n;
	vector<T> a;

	using initialize_type = function<void(T&, int)>;
	using merge_type = function<void(T&, const T&, const T&)>;
	using pushdown_type = function<void(T&, int, int, T&, T&)>;
	initialize_type initialize;
	merge_type merge;
	pushdown_type pushdown;

	void clear(int k, int L, int R)
	{
		pushdown(a[k], L, R, a[k << 1], a[k << 1 | 1]);
	}
	void update(int k)
	{
		merge(a[k], a[k << 1], a[k << 1 | 1]);
	}
	void build(int k, int L, int R)
	{
		if (L == R)
		{
			initialize(a[k], L);
			return;
		}
		int m = (L + R) >> 1;
		build(k << 1, L, m);
		build(k << 1 | 1, m + 1, R);
		update(k);
	}
	segment_tree(int n, const initialize_type& initialize, const merge_type& merge, const pushdown_type& pushdown)
	{
		assert(n >= 1);
		this->n = n;
		this->initialize = initialize;
		this->merge = merge;
		this->pushdown = pushdown;
		a = vector<T>(4 * n + 1);
		build(1, 1, n);
	}

	using modifier_type = function<void(T&, int, int)>;
	void modify(int k, int L, int R, int x, int y, const modifier_type& modifier)
	{
		if (L == x && R == y)
		{
			modifier(a[k], L, R);
			return;
		}
		int m = (L + R) >> 1;
		clear(k, L, R);
		if (y <= m)
			modify(k << 1, L, m, x, y, modifier);
		else if (x > m)
			modify(k << 1 | 1, m + 1, R, x, y, modifier);
		else
		{
			modify(k << 1, L, m, x, m, modifier);
			modify(k << 1 | 1, m + 1, R, m + 1, y, modifier);
		}
		update(k);
	}
	void modify(int x, int y, const modifier_type& modifier)
	{
		assert(1 <= x && x <= y && y <= n);
		modify(1, 1, n, x, y, modifier);
	}

	template<class result_type, class convert_type = function<result_type(const T&)>, class calculate_type = function<result_type(const result_type&, const result_type&)>>
	result_type query(int k, int L, int R, int x, int y, const convert_type& convert, const calculate_type& calculate)
	{
		if (L == x && R == y)
			return convert(a[k]);
		int m = (L + R) >> 1;
		clear(k, L, R);
		if (y <= m)
			return query<result_type>(k << 1, L, m, x, y, convert, calculate);
		if (x > m)
			return query<result_type>(k << 1 | 1, m + 1, R, x, y, convert, calculate);
		return calculate(query<result_type>(k << 1, L, m, x, m, convert, calculate), query<result_type>(k << 1 | 1, m + 1, R, m + 1, y, convert, calculate));
	}
	template<class result_type, class convert_type = function<result_type(const T&)>, class calculate_type = function<result_type(const result_type&, const result_type&)>>
	result_type query(int x, int y, const convert_type& convert, const calculate_type& calculate)
	{
		assert(1 <= x && x <= y && y <= n);
		return query<result_type>(1, 1, n, x, y, convert, calculate);
	}

	T query(int x, int y)
	{
		assert(1 <= x && x <= y && y <= n);
		function<T(const T&)> convert = [](const T& it) -> T
		{
			return it;
		};
		function<T(const T&, const T&)> calculate = [&](const T& Lc, const T& Rc) -> T
		{
			T ret;
			merge(ret, Lc, Rc);
			return ret;
		};
		return query<T>(x, y, convert, calculate);
	}
};

const ll MOD = 998244353;
const int MAXN = 100010;

int x[MAXN], v[MAXN], p[MAXN];

void solve()
{
	int n = inp();
	if (n == 1)
	{
		writeln(0);
		return;
	}
	
	const ll INV100 = power(100, MOD-2, MOD);
	for (int i = 1; i <= n; ++i)
	{
		x[i] = inp();
		v[i] = inp();
		p[i] = inp();
		p[i] = p[i] * INV100 % MOD;
	}
	
	struct event
	{
		int x, v, id, s, t;
	};
	vector<event> stamp;
	for (int i = 1; i < n; ++i)
	{
		for (int s = 0; s < 2; ++ s)
			for (int t = 0; t < 2; ++t)
			{
				if (s == 1 && t == 0) continue;
				if (s == 0 && t == 0)
				{
					if (v[i] > v[i + 1])
					{
						stamp.push_back({x[i + 1] - x[i], v[i] - v[i+1], i, s, t});
					}
				}
				else if (s == 1 && t == 1)
				{
					if (v[i] < v[i + 1])
					{
						stamp.push_back({ x[i + 1] - x[i], v[i+1] - v[i], i, s, t });
					}
				}
				else if (s == 0 && t == 1)
				{
					stamp.push_back({ x[i + 1] - x[i], v[i + 1] + v[i], i, s, t });
				}
			}
	}
	sort(stamp.begin(), stamp.end(), [](const event& a, const event& b)
		{
			return (ll)a.x * b.v < (ll)b.x * a.v;
		});
	
	struct node
	{
		ll a[2][2];
	};
	vector<node> A(n);
	for (int i = 1; i < n; ++i)
	{
		A[i].a[0][0] = p[i + 1];
		A[i].a[0][1] = p[i + 1];
		A[i].a[1][0] = (1 - p[i + 1] + MOD) % MOD;
		A[i].a[1][1] = (1 - p[i + 1] + MOD) % MOD;
	}
	auto initialize = [&](node& it, int id) -> void
	{
		it = A[id];
	};
	auto merge = [&](node& it, const node& Lc, const node& Rc) -> void
	{
		for (int i = 0; i < 2; ++ i)
			for (int j = 0; j < 2; ++j)
			{
				it.a[i][j] = 0;
				for (int k = 0; k < 2; ++k)
					it.a[i][j] += Rc.a[i][k] * Lc.a[k][j];
				it.a[i][j] %= MOD;
			}
	};
	auto pushdown = [&](node& it, int L, int R, node& Lc, node& Rc) -> void
	{
	};
	segment_tree<node> H(n-1, initialize, merge, pushdown);

	ll ans = 0;
	for (auto [x, v, id, s, t] : stamp)
	{
		node tmp;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				tmp.a[i][j] = 0;
		tmp.a[t][s] = A[id].a[t][s];
		H.modify(id, id, [&](node& it, int L, int R) -> void
			{
				it = tmp;
			});

		tmp = H.query(1, n-1);
		ll cur = (tmp.a[0][0] * p[1] % MOD + tmp.a[0][1] * (1 - p[1] + MOD) % MOD + tmp.a[1][0] * p[1] % MOD + tmp.a[1][1] * (1 - p[1] + MOD) % MOD) % MOD;
		ans = (ans + cur * x %MOD * power(v, MOD-2, MOD))%MOD;

		A[id].a[t][s] = 0;
		tmp = A[id];
		H.modify(id, id, [&](node& it, int L, int R) -> void
			{
				it = tmp;
			});
	}
	writeln(ans);
}

int main()
{
	
	//for (int T = inp(); T --; )
	solve();

	return 0;
}