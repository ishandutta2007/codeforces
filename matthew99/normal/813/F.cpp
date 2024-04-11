#define DEBUG
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <complex>
#include <iterator>
#include <limits>
#include <typeinfo>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <cctype>
#if __cplusplus >= 201103L
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define INF 0x3f3f3f3f
#ifdef DEBUG
template<typename T1,typename T2> inline ostream &operator<<(ostream &os,const pair<T1,T2> &x) {return os<<"pair<["<<x.first<<"],["<<x.second<<"]>";}
#define cvar(x) cerr << "<" << #x << ": " << (x) << ">"
#define evar(x) cvar (x) << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
template<class T> inline void DISP(const char *const s, const T &x, const int &n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP(#x " to " #n, x, n)
#else
#define debug(...) ({})
#define cvar(...) ({})
#define evar(...) ({})
#define disp(...) ({})
#endif

#define foreach(i, x) for (__typeof__((x).begin ()) i = (x).begin (); i != (x).end (); ++i)
#define CLR(x,c) memset((x),(c),sizeof(x))
#define car first
#define cdr second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define LAST(x) (x)[SZ(x)-1]
#define ALL(x) (x).begin(), (x).end()
#define CPY(x,y) memcpy((x),(y),min(sizeof(x),sizeof(y)))
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i < _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i > _end_; --i)
#define REP(i,n) for (int _end_ = (n), i = (0); i < _end_;++i)
#define PER(i,n) ROF(i,(n)-1,0)
#define FAIL(...) printf( __VA_ARGS__),exit(0)
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double Real;
typedef pair<int,int> ipair;

inline int64 fpm(int64 b, int64 e, const int64 &m) { int64 t = 1; b %= m; for (; e; e >>= 1, (b *= b) %= m) e & 1 ? (t *= b) %= m : 0; return t; }
template<typename Type> inline Type lowbit(const Type &a){return a&(-a);}
template<class T> inline bool chkmin(T &a, const T &b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, const T &b) {return a < b ? a = b, true : false;}
template<class T> inline T min(const T &a, const T &b, const T &c){return min(min(a, b), c);}
template<class T> inline T max(const T &a, const T &b, const T &c){return max(max(a, b), c);}
template<class T> inline T min(const T &a, const T &b, const T &c, const T &d){return min(min(a, b), min(c, d));}
template<class T> inline T max(const T &a, const T &b, const T &c, const T &d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(const T &a){return a*a;}
template<class T> inline T cub(const T &a){return a*a*a;}
template<typename T> T gcd(T x, T y) {for (T t; x != 0; t = x, x = y % x, y = t); return y; }

inline int Rand(const int &x,const int &y)
{
	return (uint)rand()*rand()*rand()%(y-x+1)+x;
}

inline int &Read(int &x)
{
	char c;
	int sign=1;
	while ((c=getchar())!='-'&&!isdigit(c));
	x=0;
	if (c=='-') sign=-sign;
	else x=c-48;
	while (isdigit(c=getchar())) x=x*10+c-48;
	x*=sign;
	return x;
}

const int64 OO(0x3f3f3f3f3f3f3f3fLL);
const int oo(INF);
const double pi(acos(-1));

const int maxn(300000), maxm(300000);


struct edge
{
	int x, y;
	int delt;
	edge(){}
	edge(const int &_x, const int &_y, const int &_delt = oo):x(_x), y(_y), delt(_delt){}
}e[maxm + 5];

struct node
{
	node *p;
	node *c[2];
	int Minp;
	int val;
	int size;
	bool rev;

	node(const int &_val = maxm):p(NULL), Minp(_val), val(_val), size(1), rev(0){CLR(c, 0);}

	void update()
	{
		if (this == NULL) return;
		size = 1;
		REP(i, 2) if (c[i] != NULL) size += c[i]->size; 
		Minp = val;
		REP(i, 2)
			if (c[i] != NULL)
			{
				if (e[c[i]->Minp].delt < e[Minp].delt) Minp = c[i]->Minp;
			}
	}

	void update_rev()
	{
		if (this == NULL) return;
		rev ^= 1;
		swap(c[0], c[1]);
	}

	void setc(node *u, const int &type)
	{
		if (this != NULL && type < 2) c[type] = u;
		if (u != NULL) u->p = this;
	}

	int get_pos()
	{
		if (this == NULL || p == NULL) return 2;
		REP(i, 2) if (p->c[i] == this) return i;
		return 2;
	}

	bool is_root()
	{
		return p == NULL || get_pos() >= 2;
	}

	void push_down()
	{
		if (this == NULL) return;
		if (rev)
		{
			REP(i, 2) c[i]->update_rev();
			rev = 0;
		}
	}

	node *const &get(const int &type) const
	{
		if (c[type] != NULL) c[type]->push_down();
		return c[type];
	}

	node *&get(const int &type)
	{
		if (c[type] != NULL) c[type]->push_down();
		return c[type];
	}
}a[maxn + 5], b[maxm + 5];

int n, m;
int en(0);

class lct
{
	static void Rotate(node *u)
	{
		if (u == NULL) return;
		node *p = u->p;
		if (p == NULL) return;
		bool mark = u->get_pos();
		p->p->setc(u, p->get_pos()), p->setc(u->c[mark ^ 1], mark), u->setc(p, mark ^ 1), p->update();
	}

	static void relax(node *u)
	{
		if (u == NULL) return;
		if (!(u->is_root())) relax(u->p);
		u->push_down();
	}

	static void Splay(node *u)
	{
		if (u == NULL) return;
		relax(u);
		for (;!(u->is_root());Rotate(u))
			if (!(u->p->is_root())) Rotate(u->get_pos() == u->p->get_pos() ? u->p : u);
		u->update();
	}

	static node *Access(node *u)
	{
		if (u == NULL) return NULL;
		node *v(NULL), *tmp(u);
		for (; u; v = u, u = u->p)
			Splay(u), u->setc(v, 1), u->update();
		Splay(tmp);
		return v;
	}

	static node *find_root(node *u)
	{
		if (u==NULL) return NULL;
		for (Access(u); u && u->get(0); u = u->get(0));
		return u;
	}

	static void be_root(node *u)
	{
		Access(u);
		u->update_rev();
	}

	public:

	static bool same_tree(const int &x, const int &y)
	{
		be_root(&a[x]), Access(&a[y]);
		return find_root(&a[y]) == &a[x];
	}

	static void add(const int &x, const int &y, const int &id)
	{
		Access(&a[x]), be_root(&a[y]);
		b[id] = node(id);
		a[x].setc(&b[id], 1), b[id].setc(&a[y], 1);
		b[id].update(), a[x].update();
	}

	static void del(const int &id)
	{
		be_root(&b[id]);
		Access(&b[id]);
		int &x(e[id].x), &y(e[id].y);
		Splay(&a[x]), Splay(&a[y]);
		a[x].p = a[y].p = NULL;
	}

	static int query_min(const int &x, const int &y)
	{
		be_root(&a[x]), Access(&a[y]);
		return a[y].Minp;
	}

	static int query_len(const int &x, const int &y)
	{
		be_root(&a[x]), Access(&a[y]);
		return (a[y].size - 1) >> 1;
	}

};

int event[maxm + 5] = {0};
bool vir[maxm + 5] = {0};
bool bad[maxm + 5] = {0};
int badnum(0);



int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	e[maxm] = edge(0, 0, oo + 1);
	Read(n), Read(m);
	en = 0;
	map<pair<int, int>, int> id;
	REP(i, m)
	{
		int a, b;
		Read(a), Read(b);
		--a, --b;
		if (a > b) swap(a, b);
		if (!id.count(mp(a, b)))
		{
			id[mp(a, b)] = en;
			e[en++] = edge(a, b);
			event[i] = -1;
		}
		else
		{
			int x = id[mp(a, b)];
			e[x].delt = i;
			event[i] = x;
			id.erase(mp(a, b));
		}
	}

	CLR(vir, 0);
	CLR(bad, 0);
	badnum = 0;
	int j(0);
	int cnt = 0;
	REP(i, m)
	{
		if (event[i] < 0)
		{
			int &x(e[j].x), &y(e[j].y);
			if (lct::same_tree(x, y))
			{
				int t = lct::query_min(x, y);
				cnt += lct::query_len(x, y);
				if (e[j].delt < e[t].delt) t = j;
				vir[t] = 1;
				if (t != j) lct::del(t), lct::add(x, y, j);
				cnt += lct::query_len(e[t].x, e[t].y);
				if (!(lct::query_len(e[t].x, e[t].y) & 1)) bad[t] = 1, ++badnum;
			}
			else lct::add(x, y, j);
			++j;
		}
		else
		{
			int &t(event[i]);
			if (vir[t]) 
			{
				if (bad[t]) --badnum;
			}
			else
			{
				lct::del(t);
			}	
		}
		if (badnum) puts("NO");
		else puts("YES");
	}	
	return 0;
}