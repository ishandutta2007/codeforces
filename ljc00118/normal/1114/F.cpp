#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

bool is_prime(int x) {
	for(register int i = 2; i * i <= x; i++) {
		if(x % i == 0) return 0;
	}
	return 1;
}

const int N = 400005, md = 1e9 + 7;

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

struct node_t {
	int l, r, val, tag1;
	bitset <63> wxw, tag2;
} p[N << 2];

int a[N], pri[305], inv[305], len;
int n, m;

inline void update(int u) {
	p[u].val = mul(p[u << 1].val, p[u << 1 | 1].val);
	p[u].wxw = p[u << 1].wxw | p[u << 1 | 1].wxw;
}

void add1(int u, int x) {
	p[u].val = mul(p[u].val, fpow(x, p[u].r - p[u].l + 1));
	p[u].tag1 = mul(p[u].tag1, x);
}

void add2(int u, bitset <63> x) {
	p[u].wxw |= x;
	p[u].tag2 |= x;
}

inline void pushdown(int u) {
	if(p[u].tag1 != 1) {
		add1(u << 1, p[u].tag1);
		add1(u << 1 | 1, p[u].tag1);
		p[u].tag1 = 1;
	}
	if(p[u].tag2.any()) {
		add2(u << 1, p[u].tag2);
		add2(u << 1 | 1, p[u].tag2);
		p[u].tag2.reset();
	}
}

void build(int u, int l, int r) {
	p[u].l = l; p[u].r = r; p[u].tag1 = 1;
	if(l == r) {
		p[u].val = a[l];
		for(register int i = 1; i <= len; i++) {
			if(a[l] % pri[i] == 0) {
				p[u].wxw[i] = 1;
			}
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	update(u);
}

void change(int u, int l, int r, int x, bitset <63> y) {
	if(l <= p[u].l && p[u].r <= r) {
		add1(u, x); add2(u, y);
		return;
	}
	pushdown(u);
	int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l) change(u << 1, l, r, x, y);
	if(mid + 1 <= r) change(u << 1 | 1, l, r, x, y);
	update(u);
}

pair <int, bitset <63> > query(int u, int l, int r) {
	if(l <= p[u].l && p[u].r <= r) return make_pair(p[u].val, p[u].wxw);
	pushdown(u);
	int mid = (p[u].l + p[u].r) >> 1;
	pair <int, bitset <63> > t1, t2;
	t1.first = t2.first = 1;
	t1.second.reset(); t2.second.reset();
	if(mid >= l) t1 = query(u << 1, l, r);
	if(mid + 1 <= r) t2 = query(u << 1 | 1, l, r);
	return make_pair(mul(t1.first, t2.first), t1.second | t2.second);
}

int main() {
	for(register int i = 2; i <= 300; i++) {
		if(is_prime(i)) {
			pri[++len] = i;
			inv[len] = fpow(pri[len], md - 2);
		}
	}
	read(n); read(m);
	for(register int i = 1; i <= n; i++) read(a[i]);
	build(1, 1, n);
	while(m--) {
		static char c[10];
		scanf("%s", c + 1);
		if(c[1] == 'T') {
			int l, r; read(l); read(r);
			pair <int, bitset <63> > res = query(1, l, r);
			for(register int i = 1; i <= 62; i++) {
				if(res.second[i]) {
					res.first = mul(res.first, inv[i]);
					res.first = mul(res.first, pri[i] - 1);
				}
			}
			print(res.first, '\n');
		}
		if(c[1] == 'M') {
			int l, r, x; read(l); read(r); read(x);
			bitset <63> res; res.reset();
			for(register int i = 1; i <= 62; i++) {
				if(x % pri[i] == 0) {
					res[i] = 1;
				}
			}
			change(1, l, r, x, res);
		}
	}
    return 0;
} //