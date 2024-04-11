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

const int md = 998244353, g = 3;

struct mat {
	int a[105][105];
} t;

int b[105];
int n, k, val;

mat operator * (const mat a, const mat b) {
	mat ans; memset(ans.a, 0, sizeof(ans.a));
	for(register int i = 1; i <= k; i++) {
		for(register int j = 1; j <= k; j++) {
			for(register int t = 1; t <= k; t++) {
				ans.a[i][j] = (ans.a[i][j] + (ll)a.a[i][t] * b.a[t][j]) % (md - 1);
			}
		}
	}
	return ans;
}

struct hash_map_t {
	const static int mod = 666233;

	int head[mod], nxt[mod], v[mod], val[mod], tot, last_x, last_val;

	hash_map_t () { memset(head, 0, sizeof(head)); tot = 0; }

	bool count(int x) {
		int u = x % mod;
		for(register int i = head[u]; i; i = nxt[i]) {
			if(v[i] == x) {
				last_x = x;
				last_val = val[i];
				return 1;
			}
		}
		return 0;
	}

	void add(int x, int y) {
		int u = x % mod;
		nxt[++tot] = head[u]; head[u] = tot;
		v[tot] = x; val[tot] = y;
	}

	int qry(int x) {
		if(x == last_x) return last_val;
		if(count(x)) return last_val;
		return -1;
	}
} wxw;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int exgcd(int a, int b, int &x, int &y) {
	if(b == 0) { x = 1; y = 0; return a; }
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x; return d;
}

int inv(int a, int p) {
	int x, y;
	exgcd(a, p, x, y);
	return (x % p + p) % p;
}

int bsgs(int a, int b, int p) {
	if(a == 0) return b == 0 ? 1 : -1;
	int m = ceil(sqrt(p)), now = 1;
	for(register int i = 0; i < m; i++) {
		if(!wxw.count(now)) wxw.add(now, i);
		now = (ll)now * a % p;
	}
	int tmp = inv(now, p); now = b;
	for(register int i = 0; i < m; i++) {
		if(wxw.count(now)) return i * m + wxw.qry(now);
		now = (ll)now * tmp % p;
	}
	return -1;
}

mat fpow(mat x, int y) {
	mat ans = x; --y;
	while(y) {
		if(y & 1) ans = ans * x;
		y >>= 1; x = x * x;
	}
	return ans;
}

inline int fpow(int x, int y, int md) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ll)ans * x % md;
		y >>= 1; x = (ll)x * x % md;
	}
	return ans;
}

int main() {
	read(k);
	for(register int i = 1; i <= k; i++) read(b[i]);
	read(n); read(val); n -= k; val = bsgs(3, val, md);
	for(register int i = 1; i <= k; i++) t.a[1][i] = b[i];
	for(register int i = 2; i <= k; i++) t.a[i][i - 1] = 1;
	t = fpow(t, n); int res = t.a[1][1];
	int d = gcd(res, md - 1);
	if(val % d != 0) { cout << -1 << endl; return 0; }
	val /= d; res /= d; int p = (md - 1) / d;
	cout << fpow(3, (ll)val * inv(res, p) % p, md) << endl;
    return 0;
}