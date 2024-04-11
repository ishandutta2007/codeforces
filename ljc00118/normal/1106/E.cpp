#include <bits/stdc++.h>
#define int long long
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

const int N = 1e5 + 5, INF = 0x7f7f7f7f7f7f7f7f;

struct ele {
	int s, t, d, w;
	bool operator < (const ele A) const { return s < A.s; }
} a[N];

struct ele2 {
	int d, w;
	bool operator < (const ele2 A) const {
		if(w == A.w) return d < A.d;
		return w < A.w;
	}
};

multiset <ele2> wxw;
multiset <ele2> :: iterator it;
multiset <pii> wxw2;
int f[N][205], d[N], w[N];
int n, m, k, big, ans = INF;

#undef int
int main() {
#define int long long
	memset(f, 0x7f, sizeof(f));
	read(n); read(m); read(k);
	for(register int i = 1; i <= k; i++) read(a[i].s), read(a[i].t), read(a[i].d), read(a[i].w);
	sort(a + 1, a + k + 1);
	int fir = 1;
	for(register int i = 1; i <= n; i++) {
		while(fir <= k && a[fir].s == i) { wxw.insert((ele2) {a[fir].d, a[fir].w}); wxw2.insert(make_pair(a[fir].t, fir)); ++fir; }
		while(!wxw2.empty() && wxw2.begin() -> first == i - 1) {
			int t = wxw2.begin() -> second;
			wxw2.erase(wxw2.begin());
			wxw.erase(wxw.find((ele2) {a[t].d, a[t].w}));
		}
		if(!wxw.empty()) {
			it = wxw.end(); --it;
			d[i] = it -> d;
			w[i] = it -> w;
		}
	}
	f[0][0] = 0;
	for(register int i = 0; i <= n; i++) {
		for(register int j = 0; j <= m; j++) {
			if(f[i][j] == INF) continue;
			if(j != m) f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j]);
			if(d[i]) f[d[i] + 1][j] = min(f[d[i] + 1][j], f[i][j] + w[i]);
			else f[i + 1][j] = min(f[i + 1][j], f[i][j]);
		}
	}
	for(register int i = 0; i <= m; i++) ans = min(ans, f[n + 1][i]);
	print(ans, '\n');
    return 0;
}