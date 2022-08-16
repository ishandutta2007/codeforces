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

const int MOD = 1000000007;

struct mod_int {
	int val;

	mod_int(long long v = 0) {
		if (v < 0)
			v = v % MOD + MOD;

		if (v >= MOD)
			v %= MOD;

		val = v;
	}

	static int mod_inv(int a, int m = MOD) {
		// https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
		int g = m, r = a, x = 0, y = 1;

		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}

		return x < 0 ? x + m : x;
	}

	explicit operator int() const {
		return val;
	}

	mod_int& operator+=(const mod_int& other) {
		val += other.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}

	mod_int& operator-=(const mod_int& other) {
		val -= other.val;
		if (val < 0) val += MOD;
		return *this;
	}

	static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
		return x % m;
	}

	mod_int& operator*=(const mod_int& other) {
		val = fast_mod((uint64_t)val * other.val);
		return *this;
	}

	mod_int& operator/=(const mod_int& other) {
		return *this *= other.inv();
	}

	friend mod_int operator+(const mod_int& a, const mod_int& b) { return mod_int(a) += b; }
	friend mod_int operator-(const mod_int& a, const mod_int& b) { return mod_int(a) -= b; }
	friend mod_int operator*(const mod_int& a, const mod_int& b) { return mod_int(a) *= b; }
	friend mod_int operator/(const mod_int& a, const mod_int& b) { return mod_int(a) /= b; }

	mod_int& operator++() {
		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}

	mod_int& operator--() {
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}

	mod_int operator++(int) { mod_int before = *this; ++* this; return before; }
	mod_int operator--(int) { mod_int before = *this; --* this; return before; }

	mod_int operator-() const {
		return val == 0 ? 0 : MOD - val;
	}

	bool operator==(const mod_int& other) const { return val == other.val; }
	bool operator!=(const mod_int& other) const { return val != other.val; }

	mod_int inv() const {
		return mod_inv(val);
	}

	mod_int pow(long long p) const {
		assert(p >= 0);
		mod_int a = *this, result = 1;

		while (p > 0) {
			if (p & 1)
				result *= a;

			a *= a;
			p >>= 1;
		}

		return result;
	}

	friend ostream& operator<<(ostream& stream, const mod_int& m) {
		return stream << m.val;
	}
};

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

	int find(int k, int L, int R, int c)
	{
		if (a[k].minv >= c) return -1;
		if (L == R) return L;
		int m = (L + R) / 2;
		if (a[k << 1 | 1].minv < c)
			return find(k << 1 | 1, m + 1, R, c);
		else
			return find(k << 1, L, m, c);
	}
};

int n, k, L;

void solve()
{
	read(n, k, L);
	vector<int> px, py;
	px = { 0, L + 1 };
	py = { 0, L + 1 };
	vector<tuple<int, int, int>> v(n);
	for (auto &[x, y, c] : v)
	{
		read(x, y, c);
		x += 1, y += 1, c -= 1;
		px.push_back(x);
		py.push_back(y);
	}

	sort(px.begin(), px.end());
	px.erase(unique(px.begin(), px.end()), px.end());
	sort(py.begin(), py.end());
	py.erase(unique(py.begin(), py.end()), py.end());
	int nx = px.size() - 2, ny = py.size() - 2;

	vector<vector<pii>> w(ny + 1);
	for (auto& [x, y, c] : v)
	{
		x = lower_bound(px.begin(), px.end(), x) - px.begin();
		y = lower_bound(py.begin(), py.end(), y) - py.begin();
		w[y].push_back({ x, c });
	}

	const int INF = L + 1;
	mod_int res = 0;

	for (int y2 = 1; y2 <= ny; ++y2)
	{
		vector<multiset<int>> s(k, {0, nx + 1});
		vector<vector<int>> cur(nx + 1);
		vector<vector<pii>> w(ny + 1);
		for (auto& [x, y, c] : v)
		{
			if (y <= y2)
			{
				s[c].insert(x);
				cur[x].push_back(c);
				w[y].push_back({ x, c });
			}
		}

		vector<int> init(nx + 1, INF);
		int flag = 0;
		vector<int> has(k);
		for (int x1 = 1, x2 = 0; x1 <= nx; ++x1)
		{
			while (flag != k && x2 < nx)
			{
				x2++;
				for (auto c : cur[x2])
				{
					if (!has[c]++) flag++;
				}
			}
			init[x1] = (flag == k) ? px[x2] : INF;
			for (auto c : cur[x1])
			{
				if (!--has[c]) flag--;
			}
		}

		struct node
		{
			int minv;
			mod_int sum;
			int tag;
		};
		auto initialize = [&](node& it, int id) -> void
		{
			it.minv = init[id];
			it.sum = mod_int(it.minv) * (px[id] - px[id - 1]);
			it.tag = -1;
		};
		auto merge = [&](node& it, const node& Lc, const node& Rc) -> void
		{
			it.minv = min(Lc.minv, Rc.minv);
			it.sum = Lc.sum + Rc.sum;
			it.tag = -1;
		};
		auto pushdown = [&](node& it, int L, int R, node& Lc, node& Rc) -> void
		{
			if (it.tag != -1)
			{
				int m = (L + R) >> 1;
				Lc.minv = it.tag;
				Lc.sum = mod_int(it.tag) * (px[m] - px[L - 1]);
				Lc.tag = it.tag;
				Rc.minv = it.tag;
				Rc.sum = mod_int(it.tag) * (px[R] - px[m]);
				Rc.tag = it.tag;
				it.tag = -1;
			}
		};
		segment_tree<node> H(nx, initialize, merge, pushdown);

		for (int y1 = 1; y1 <= y2; ++y1)
		{
			res += (mod_int(INF) * px[nx] - H.query(1, nx).sum) * (py[y1] - py[y1 - 1]) * (py[y2 + 1] - py[y2]);
			for (auto [x, c] : w[y1])
			{
				s[c].erase(s[c].find(x));
				auto it = s[c].lower_bound(x);
				int nxt = *it;
				int pre = (nxt == x) ? x : *--it;
				if (pre + 1 <= x)
				{
					int pos = H.find(1, 1, H.n, px[nxt]);
					if (pos != -1)
					{
						freshmin(pos, x);
						if (pre + 1 <= pos)
							H.modify(pre + 1, pos, [&](node& it, int L, int R)
								{
									it.tag = px[nxt];
									it.minv = px[nxt];
									it.sum = mod_int(it.tag) * (px[R] - px[L - 1]);
								});
					}
				}
			}
		}
	}

	writeln(int(res));
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