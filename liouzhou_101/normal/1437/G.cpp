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
mt19937 rd(678);

using namespace io;

template<class T>
inline bool freshmin(T& a, const T& b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	else
		return false;
}

template<class T>
inline bool freshmax(T& a, const T& b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	else
		return false;
}

template<class T>
auto arr(int n = 0)
{
	return vector<T>(n);
}

template<class T, class... Args>
auto arr(int n, Args... args)
{
	return vector<decltype(arr<T>(args...))>(n, arr<T>(args...));
}

//int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
//int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

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

#ifdef ONLINE_JUDGE
const int OJ = 1;
#else
const int OJ = 0;
#endif

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

	using checker_type = function<bool(T&, int, int)>;
	int find_first_of(int k, int L, int R, const checker_type& checker)
	{
		if (L == R)
		{
			assert(checker(a[k], L, R));
			return L;
		}
		clear(k, L, R);
		int m = (L + R) / 2;
		if (checker(a[k << 1], L, m))
			return find_first_of(k << 1, L, m, checker);
		else
			return find_first_of(k << 1 | 1, m + 1, R, checker);
	}
	int find_first_of(const checker_type& checker)
	{
		if (!checker(a[1], 1, n)) return n + 1;
		return find_first_of(1, 1, n, checker);
	}

	// find_last_of not checked
	int find_last_of(int k, int L, int R, const checker_type& checker)
	{
		if (L == R)
		{
			assert(checker(a[k], L, R));
			return L;
		}
		clear(k, L, R);
		int m = (L + R) / 2;
		if (checker(a[k << 1 | 1], m + 1, R))
			return find_last_of(k << 1 | 1, m + 1, R);
		else
			return find_last_of(k << 1, L, m);
	}
	int find_last_of(const checker_type& checker)
	{
		if (!checker(a[1], 1, n)) return 0;
		return find_last_of(1, 1, n, checker);
	}
};

static const int MAXN = 300010; // number of nodes in AC automaton
static const int MAXM = 26; // cardinal of alphabet

int n, m;
int weight[MAXN], at[MAXN];

int tot;

struct node
{
	node* next[MAXM];
	node* fail;
	int val;
	multiset<int> has;
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

node* add(string s, int id)
{
	node* it = root;
	for (auto c : s)
	{
		int x = c - 'a';
		if (!it->next[x]) it->next[x] = new_node();
		it = it->next[x];
	}
	it->val = 1;
	weight[id] = 0;
	at[id] = it - tree;
	it->has.insert(0);
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

static char buf[MAXN];

vector<int> v[MAXN];
int depth[MAXN], sz[MAXN], pre[MAXN];

void dfs(int x)
{
	sz[x] = 1;
	for (auto y : v[x])
	{
		pre[y] = x;
		depth[y] = depth[x] + 1;
		dfs(y);
		sz[x] += sz[y];
	}
}

int times, X[MAXN], Y[MAXN], r[MAXN];
int from[MAXN];

void dfs2(int x)
{
	X[x] = ++times;
	r[times] = x;
	if (!v[x].empty())
	{
		int son = *max_element(v[x].begin(), v[x].end(), [&](int i, int j)
			{
				return sz[i] > sz[j];
			});
		from[son] = from[x];
		dfs2(son);
		for (auto y : v[x])
		{
			if (y == son) continue;
			from[y] = y;
			dfs2(y);
		}
	}
	Y[x] = times;
}

void solve()
{
	read(n, m);
	init();
	for (int i = 1; i <= n; ++i)
	{
		read(buf);
		add(buf, i);
	}
	build();
	for (int i = 2; i <= tot; ++i)
	{
		v[tree[i].fail - tree].push_back(i);
	}
	dfs(1);
	from[1] = 1;
	dfs2(1);
	struct node
	{
		int val;
	};
	auto initialize = [&](node& it, int id) -> void
	{
		it.val = tree[r[id]].has.empty() ? -1 : *tree[r[id]].has.rbegin();
	};
	auto merge = [&](node& it, const node& Lc, const node& Rc) -> void
	{
		it.val = max(Lc.val, Rc.val);
	};
	auto pushdown = [&](node& it, int L, int R, node& Lc, node& Rc) -> void
	{
	};
	segment_tree<node> H(tot, initialize, merge, pushdown);
	
	while (m--)
	{
		int op;
		read(op);
		if (op == 1)
		{
			int id, val;
			read(id, val);
			H.modify(X[at[id]], X[at[id]], [&](node& it, int, int)
				{
					tree[at[id]].has.erase(tree[at[id]].has.lower_bound(weight[id]));
					weight[id] = val;
					tree[at[id]].has.insert(weight[id]);
					it.val = *tree[at[id]].has.rbegin();
				});
		}
		else
		{
			int res = -1;
			read(buf);
			int len = strlen(buf);
			::node* cur = root;
			for (int i = 0; i < len; ++i)
			{
				cur = cur->next[buf[i] - 'a'];
				int tmp = cur - tree;
				while (tmp)
				{
					freshmax(res, H.query(X[from[tmp]], X[tmp]).val);
					tmp = pre[from[tmp]];
				}
			}
			writeln(res);
		}
	}
}

int main()
{
	if (!OJ)
	{
		freopen("try.in", "r", stdin);
		freopen("try.out", "w", stdout);
	}

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