#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
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

const int N = 2e5 + 5, md = 998244353;

inline int mul(int x, int y) { return (ll)x * y % md; }

inline int add(int x, int y) {
	x += y;
	if(x >= md) x -= md;
	return x;
}

inline int sqr(int x) { return mul(x, x); }

inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = sqr(x);
	}
	return ans;
}

int a[N], s[N], f[N], fac[N];
int n, inv2 = (md + 1) / 2, ans1;

inline int lowbit(int x) { return x & -x; }

void change(int x, int y) {
	for(register int i = x; i <= n; i += lowbit(i))
		f[i] += y;
}

int query(int x) {
	int ans = 0;
	for(register int i = x; i; i -= lowbit(i))
		ans += f[i];
	return ans;
}

int main() {
	read(n); fac[0] = 1;
	for(register int i = 1; i <= n; i++) read(a[i]), fac[i] = mul(fac[i - 1], i), s[i] = 1;
	for(register int i = n; i >= 1; i--) {
		if(a[i] == -1) continue;
		ans1 = add(ans1, query(a[i]));
		change(a[i], 1);
	}
	memset(f, 0, sizeof(f));
	for(register int i = 1; i <= n; i++) {
		if(a[i] != -1) s[a[i]] = 0;
	}
	for(register int i = 1; i <= n; i++) s[i] += s[i - 1];
	ans1 = mul(ans1, fac[s[n]]);
	for(register int i = 1; i <= s[n]; i++) f[i] = add(f[i - 1], mul(mul(fac[s[n]], fpow(i, md - 2)), mul(i - 1, mul(i, inv2))));
	ans1 = add(ans1, f[s[n]]); memset(f, 0, sizeof(f));
	for(register int i = 1; i <= n; i++) if(a[i] == -1) change(i, 1);
	for(register int i = 1; i <= n; i++) {
		if(a[i] == -1) continue;
		int val = mul(s[a[i]], query(n) - query(i));
		val = add(val, mul(s[n] - s[a[i]], query(i)));
		val = mul(val, fac[s[n] - 1]);
		ans1 = add(ans1, val);
	}
//	cout << ans1 << endl;
	print(mul(ans1, fpow(fac[s[n]], md - 2)), '\n');
	return 0;
}

// 1 2 3 -> 0
// 1 3 2 -> 1
// 2 1 3 -> 1
// 2 3 1 -> 2
// 3 1 2 -> 2
// 3 2 1 -> 3