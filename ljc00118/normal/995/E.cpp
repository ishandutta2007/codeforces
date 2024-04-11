#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
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

map <int, vector <int> > wxw;
int u, v, p, tmp;

inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ll)ans * x % p;
		y >>= 1; x = (ll)x * x % p;
	}
	return ans;
}

void add(int u) {
	vector <int> res;
	for(register int i = 1; i <= 100; i++) {
		int opt = rand() % 3 + 1;
		if(opt == 1) {
			++u;
			if(u == p) u = 0;
		}
		if(opt == 2) {
			--u;
			if(u == -1) u = p - 1;
		}
		if(opt == 3) {
			u = fpow(u, p - 2);
		}
		res.push_back(opt);
		if(!wxw.count(u)) wxw[u] = res;
	}
}

void qry(int u) {
	vector <int> res;
	for(register int i = 1; i <= 100; i++) {
		int opt = rand() % 3 + 1;
		if(opt == 2) {
			++u;
			if(u == p) u = 0;
		}
		if(opt == 1) {
			--u;
			if(u == -1) u = p - 1;
		}
		if(opt == 3) {
			u = fpow(u, p - 2);
		}
		res.push_back(opt);
		if(wxw.count(u)) {
			vector <int> ans = wxw[u];
			reverse(res.begin(), res.end());
			cout << ans.size() + res.size() << endl;
			for(register unsigned i = 0; i < ans.size(); i++) print(ans[i], ' ');
			for(register unsigned i = 0; i < res.size(); i++) print(res[i], ' ');
			putchar('\n'); exit(0);
		}
	}
}

int main() {
	srand(20050426);
	read(u); read(v); read(p);
	tmp = max((int)sqrt(tmp), 2333);
	for(register int i = 1; i <= tmp; i++) add(u);
	while(1) qry(v);
	return 0;
}