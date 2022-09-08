#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
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

const int N = 1e5 + 5, P = 1e9 + 7;

struct ele {
	int l, r;
	bool operator < (const ele A) const { return l < A.l; }
}a[N];

multiset <int> t;
multiset <int> :: iterator it;
int n, y, x, ans;

inline int mul(int x, int y) { return (int)(1ll * x * y % P); }

int main() {
	read(n); read(x); read(y);
	for(register int i = 1; i <= n; i++) read(a[i].l), read(a[i].r);
	sort(a + 1, a + n + 1);
	for(register int i = 1; i <= n; i++) {
		it = t.lower_bound(a[i].l);
		if(it == t.begin()) {
			ans = (ans + x) % P;
			ans = (ans + mul(a[i].r - a[i].l, y)) % P;
			t.insert(a[i].r);
			continue;
		}
		--it;
		if(1ll * (a[i].l - *it) * y <= x) {
			ans = (ans + mul(a[i].r - *it, y)) % P;
			t.erase(it); t.insert(a[i].r);
		} else {
			ans = (ans + x) % P;
			ans = (ans + mul(a[i].r - a[i].l, y)) % P;
			t.insert(a[i].r);
			continue;
		}
	}
	cout << ans << endl;
	return 0;
}