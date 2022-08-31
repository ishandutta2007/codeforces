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
const ll MOD = 1000000007;
const int INF = 1000000010;
const ll INFll = 4000000000000000000LL;
const int MAXN = 500010;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

ld det(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

struct node
{
	node* son[2], * pre;
	int sz;
	int val, sum;
	node();
};

node* nil = new node;

node::node()
{
	son[0] = son[1] = pre = nil;
	val = 0;
	sum = 0;
	sz = 0;
}

struct splay_tree
{

	node* root;

	splay_tree()
	{
		nil->son[0] = nil->son[1] = nil->pre = nil;
		root = nil;
	}

	void update(node* x)
	{
		x->sz = x->son[0]->sz + x->son[1]->sz + 1;
		x->sum = x->son[0]->sum + x->son[1]->sum + x->val;
	}

	void rotate(node* x, int p)
	{
		node* y = x->pre;
		if (x->son[p] != nil)
			x->son[p]->pre = y;
		y->son[p ^ 1] = x->son[p];
		x->son[p] = y;
		if (y == y->pre->son[0])
			y->pre->son[0] = x;
		else if (y == y->pre->son[1])
			y->pre->son[1] = x;
		x->pre = y->pre;
		y->pre = x;
		update(y);
		update(x);
	}

	void splay(node* x, node* p = nil)
	{
		while (x->pre != p)
		{
			node* y = x->pre;
			if (y->pre == p)
				if (x == y->son[0])
					rotate(x, 1);
				else
					rotate(x, 0);
			else
				if (y == y->pre->son[0])
					if (x == y->son[0])
					{
						rotate(y, 1);
						rotate(x, 1);
					}
					else
					{
						rotate(x, 0);
						rotate(x, 1);
					}
				else
					if (x == y->son[0])
					{
						rotate(x, 1);
						rotate(x, 0);
					}
					else
					{
						rotate(y, 0);
						rotate(x, 0);
					}
		}
		if (p == nil) root = x;
	}

	node* insert(int v)
	{
		if (root == nil)
		{
			root = new node;
			root->val = v;
			return root;
		}
		node* x = root;
		while (1)
		{
			if (x->val > v)
			{
				if (x->son[0] == nil)
				{
					x->son[0] = new node;
					x->son[0]->pre = x;
					x = x->son[0];
					x->val = v;
					break;
				}
				x = x->son[0];
			}
			else
			{
				if (x->son[1] == nil)
				{
					x->son[1] = new node;
					x->son[1]->pre = x;
					x = x->son[1];
					x->val = v;
					break;
				}
				x = x->son[1];
			}
		}
		splay(x);
		return x;
	}

	node* last_node(node* x)
	{
		node* p = x->son[0];
		while (p->son[1] != nil) p = p->son[1];
		return p;
	}

	node* next_node(node* x)
	{
		node* p = x->son[1];
		while (p->son[0] != nil) p = p->son[0];
		return p;
	}

	void erase(node* x)
	{
		splay(x);
		node* L = last_node(x);
		node* R = next_node(x);
		if (L == nil && R == nil)
		{
			root = nil;
		}
		else if (L == nil)
		{
			splay(R);
			R->son[0] = nil;
			update(R);
		}
		else if (R == nil)
		{
			splay(L);
			L->son[1] = nil;
			update(L);
		}
		else
		{
			splay(L);
			splay(R, L);
			R->son[0] = nil;
			update(R);
			update(L);
		}
	}

	node* get_last(node* x)
	{
		splay(x);
		node* p = last_node(x);
		if (p != nil) splay(p);
		return p;
	}

	node* get_next(node* x)
	{
		splay(x);
		node* p = next_node(x);
		if (p != nil) splay(p);
		return p;
	}

	int size() const
	{
		return root->sz;
	}
	void splay_kth(int k)
	{
		node* x = root;
		while (1)
		{
			if (x->son[0]->sz + 1 == k) break;
			if (x->son[0]->sz >= k)
				x = x->son[0];
			else
			{
				k -= x->son[0]->sz + 1;
				x = x->son[1];
			}
		}
		splay(x);
	}
	int prefix_sum(int k)
	{
		if (k == 0) return 0;
		splay_kth(k);
		return root->son[0]->sum + root->val;
	}
};

void solve()
{
	int n;
	read(n);
	vector<int> a(n);
	input(a);
	for (auto& x : a) x -= 1;

	vector<int> b(n);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += b[i] = a[i] == i;
	}

	if (sum == n)
	{
		return writeln(0);
	}

	int L = 0, R = n - 1;
	while (b[L] == 1) ++L;
	while (b[R] == 1) --R;
	int flag = 0;
	for (int i = L + 1; i <= R - 1; ++i) if (b[i] == 1) flag = 1;
	if (flag == 0)
		return writeln(1);
	else
		return writeln(2);
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