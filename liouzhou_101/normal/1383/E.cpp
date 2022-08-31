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

const int MAXN = 1000010;

char buf[MAXN];

void solve()
{
	read(buf);
	string s = buf;
	int n = s.size();

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		cnt += s[i] == '0';
	if (cnt == n)
	{
		writeln(n);
		return;
	}
	int L = 0;
	while (L < n && s[L] == '0') ++L;
	int R = n - 1;
	while (R >= 0 && s[R] == '0') --R;
	int left = L, right = n - R - 1;

	s = s.substr(L, n - left - right);
	n = s.size();

	vector<vector<int>> nxt(n + 1, vector<int>(2, n));
	for (int i = n - 1; i >= 0; --i)
	{
		nxt[i] = nxt[i + 1];
		nxt[i][s[i] - '0'] = i;
	}
	/*
	string tmp;
	int ans = 0;
	function<void(int)> dfs = [&](int x)
	{
		if (!tmp.empty() && tmp.back() == '1')
		{
			cout << tmp << endl; ans += 1;
		}
		if (x == n)
		{
			//ans += 1;
			return;
		}
		if (x > 0)
		for (int i = x; i < n; ++i)
			if (s[i] == '0')
			{
				tmp += '0';
				dfs(i + 1);
				tmp.pop_back();
				break;
			}
		for (int i = x; i < n; ++i)
			if (s[i] == '1')
			{
				tmp += '1';
				dfs(i + 1);
				tmp.pop_back();
				break;
			}
	};
	
	dfs(0);
	writeln(ans);
	*/

	assert(s[0] == '1' && s[n - 1] == '1');

	vector<int> q;
	for (int i = 0; i < n; ++i)
		q.push_back(n);
	vector<int> xxx(n);
	for (int i = n - 1; i >= 0; --i)
	{
		if (s[i] == '0')
		{
			xxx[i] = nxt[i][0] = q.back();
			q.push_back(i);
		}
		else
		{
			while (i >= 0 && s[i] == '1')
			{
				xxx[i] = nxt[i][0] = q.back();
				--i;
			}
			q.pop_back();
			++i;
		}
	}

	vector<mod_int> f(n + 5, 0);
	f[1] = 1;
	mod_int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i >= 1 && s[i - 1] == '1')
			res += f[i];

		//if (i >= 1 && s[i - 1] == '0' && nxt[i][1] == n)
		//	res += f[i];

		if (i == n) break;
		//if (s[i] == '0')
		//	f[i + 1] += f[i];
		if (i >= 1) f[nxt[i - 1][0] + 1] += f[i];
		f[nxt[i][1] + 1] += f[i];
	}
	res *= left+1;
	res *= right+1;
	writeln(int(res));
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