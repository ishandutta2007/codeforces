// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

#define int long long

int x, d[60], ct;

bool inline obt() {
	return d[0];
}

vector<int> a;

set<int> s;

struct Node{
	int a, b; char c;
};

vector<Node> q;

// 0  1  

bool inline tr(int x, int y, int o) {
	assert(s.count(x));
	assert(s.count(y));
	int z = o ? x + y : x ^ y;
	if (z >= (1ll << 60)) return 0;
	if (s.count(z)) return 0;
//	cout << x << " " << y << " " << o << " ee" << ct << endl;
	s.insert(z), a.pb(z);
	q.pb((Node) { x, y, o ? '+' : '^' });
	return 1;
}

void inline rjz(int x) {
	for (int i = 59; ~i; i--) cout << (x >> i & 1);
	
}

mt19937 rnd(444);

void inline ins(int x) {
	for (int i = 59; ~i; i--) {
		if (x >> i & 1) {
			if (!d[i]) {
				d[i] = x;
				++ct;
				return;
			} else {
				tr(x, d[i], 0);
				x ^= d[i];
			}
		}
	}
}

bool inline chk(int x) {
	if (x >= (1ll << 60)) return 0;
	for (int i = 59; ~i; i--) {
		if (x >> i & 1) {
			if (!d[i]) return 1;
			x ^= d[i];
		}
	}
	return 0;
}

int inline gr() {
	int ret = 0;
	for (int i = 59; ~i; i--) {
		if (d[i]) {
			if ((rnd() & 1)) {
				tr(ret, d[i], 0);
				ret ^= d[i];
			}
		}
	}
	return ret;
}

signed main() {
	read(x); a.pb(x); s.insert(x);
//	rjz(x); puts("");
	ins(x);
	tr(x, x, 0);
	while (!obt()) {
		int A = gr(), B = gr();
		if (chk(A + B) && tr(A, B, 1)) ins(A + B);
	}
	printf("%lu\n", q.size());
	for (auto o: q)
		printf("%lld %c %lld\n", o.a, o.c, o.b);
    return 0;
}