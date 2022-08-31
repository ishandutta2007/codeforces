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

const int MAXN = 1000010;

namespace treap
{
	using random_type = u32;

	template<class data_type>
	struct node
	{
		node* Lc, * Rc;
		data_type val;
		random_type rnd;
		int sz;

		data_type sum;

		node()
		{
			Lc = Rc = 0;
			val = data_type();
			rnd = 0;
			sz = 0;
			sum = val;
		}
		void update()
		{
			this->sz = this->Lc->sz + this->Rc->sz + 1;
			this->sum = this->Lc->sum + this->Rc->sum + this->val;
		}
	};

	template<class data_type>
	struct treap
	{
		using node = ::treap::node<data_type>;

		using pnn = pair<node*, node*>;
		node* nil, * root;

		node* new_node(const data_type& val)
		{
			node* it = new node();
			it->Lc = it->Rc = nil;
			it->val = val;
			it->rnd = rd();
			it->sz = 1;

			it->sum = it->val;
			return it;
		}

		void init()
		{
			nil = new_node(0);
			nil->Lc = nil->Rc = nil;
			nil->val = data_type();
			nil->sz = 0;
			root = nil;
		}

		treap()
		{
			init();
		}

		node* merge(node* x, node* y)
		{
			if (x == nil) return y;
			if (y == nil) return x;
			if (x->rnd < y->rnd)
			{
				x->Rc = merge(x->Rc, y);
				x->update();
				return x;
			}
			else
			{
				y->Lc = merge(x, y->Lc);
				y->update();
				return y;
			}
		}

		// left tree <= val && right tree > val
		pnn split_upper_bound(node* x, const data_type& val)
		{
			if (x == nil) return { nil, nil };
			if (val < x->val)
			{
				auto [left, tmp] = split_upper_bound(x->Lc, val);
				x->Lc = tmp;
				x->update();
				return { left, x };
			}
			else
			{
				auto [tmp, right] = split_upper_bound(x->Rc, val);
				x->Rc = tmp;
				x->update();
				return { x, right };
			}
		}

		// left tree < val && right tree >= val
		pnn split_lower_bound(node* x, const data_type& val)
		{
			if (x == nil) return { nil,nil };
			if (val <= x->val)
			{
				auto [left, tmp] = split_lower_bound(x->Lc, val);
				x->Lc = tmp;
				x->update();
				return { left, x };
			}
			else
			{
				auto [tmp, right] = split_lower_bound(x->Rc, val);
				x->Rc = tmp;
				x->update();
				return { x, right };
			}
		}

		// left tree size = k && right tree size = n-k
		pnn split_sz(node* x, int k)
		{
			if (x == nil) return { nil, nil };
			if (k <= x->Lc->sz)
			{
				auto [left, tmp] = split_sz(x->Lc, k);
				x->Lc = tmp;
				x->update();
				return { left, x };
			}
			else
			{
				auto [tmp, right] = split_sz(x->Rc, k - x->Lc->sz - 1);
				x->Rc = tmp;
				x->update();
				return { x, right };
			}
		}

		void insert(const data_type& val)
		{
			auto [left, right] = split_lower_bound(root, val);
			root = merge(merge(left, new_node(val)), right);
		}

		// delete only one occurrence of val
		void erase(const data_type& val)
		{
			auto [x, y] = split_upper_bound(root, val);
			auto [left, right] = split_lower_bound(x, val);
			root = merge(merge(left, merge(right->Lc, right->Rc)), y);
		}

		int rank(const data_type& val)
		{
			auto [left, right] = split_lower_bound(root, val);
			int res = left->sz + 1;
			root = merge(left, right);
			return res;
		}

		data_type kth(node* r, int k)
		{
			auto [x, y] = split_sz(r, k);
			auto [left, right] = split_sz(x, k - 1);
			data_type res = right->val;
			r = merge(merge(left, right), y);
			return res;
		}

		data_type kth(int k)
		{
			return kth(root, k);
		}

		data_type upper_bound(const data_type& val)
		{
			auto [left, right] = split_upper_bound(root, val);
			data_type res = kth(right, 1);
			root = merge(left, right);
			return res;
		}

		data_type down_bound(const data_type& val)
		{
			auto [left, right] = split_lower_bound(root, val);
			data_type res = kth(left, left->sz);
			root = merge(left, right);
			return res;
		}
	};
}


void solve()
{
	int n;
	read(n);
	multiset<ll> H[2];
	ll sum = 0;
	treap::treap<ll> tr;
	while (n--)
	{
		ll tp, d;
		read(tp, d);
		if (tp == 0)
		{
			if (d > 0)
			{
				sum += d;
				H[0].insert(d);
				tr.insert(d);
			}
			else
			{
				d = -d;
				sum -= d;
				H[0].erase(H[0].lower_bound(d));
				tr.erase(d);
			}
		}
		else
		{
			if (d > 0)
			{
				sum += d;
				H[1].insert(d);
				tr.insert(d);
			}
			else
			{
				d = -d;
				sum -= d;
				H[1].erase(H[1].lower_bound(d));
				tr.erase(d);
			}
		}
		ll tot = H[0].size() + H[1].size();
		ll magic = H[1].size();
		if (magic == 0)
			writeln(sum);
		else
		{
			ll mind = *H[1].begin();
			tr.erase(mind);

			auto [left, right] = tr.split_sz(tr.root, max(tot - 1 - magic, 0LL));
			writeln(sum + right->sum);
			tr.root = tr.merge(left, right);

			tr.insert(mind);
		}
	}
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