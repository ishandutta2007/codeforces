#include <bits/stdc++.h>
#define int long long
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

int t, n, m, a, b, c, d, e, f, g, h, A, B, C, D;

typedef pair < int, int > pii;
pii ans, dec1, dec2;

pii operator + (const pii &a, const pii &b) { return make_pair(a.first + b.first, a.second + b.second); }
pii operator - (const pii &a, const pii &b) { return make_pair(a.first - b.first, a.second - b.second); }

int get(int a, int b, int c, int d) {
	if (a > c || b > d) return 0;
	return (c - a + 1) * (d - b + 1);
}

inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }

pii calc(int a, int b, int c, int d) {
	if (a > c || b > d) return make_pair(0, 0);
	int qwq = (c - a + 1) * (d - b + 1);
	if (qwq % 2 == 1) {
		if ((a + b) & 1) return make_pair(qwq / 2, (qwq + 1) / 2);
		else return make_pair((qwq + 1) / 2, qwq / 2);
	}
	// qwq
	return make_pair(qwq / 2, qwq / 2);
}

#undef int
int main() {
#define int long long
	read(t);
	while (t--) {
		read(n), read(m); read(a), read(b), read(c), read(d); read(e), read(f), read(g), read(h);
		A = max(a, e), B = max(b, f);
		C = min(c, g), D = min(d, h);
		ans.first = ans.second = 0;
		ans = calc(1, 1, n, m);
		dec1 = calc(a, b, c, d); int sum1 = a + b + c + d;
		dec2 = calc(e, f, g, h); int sum2 = e + f + g + h; a += sum2; a -= sum1;
		a += (sum1 - sum2);
		ans = ans - dec1 - dec2; ans = ans + calc(A, B, C, D); ans = ans + make_pair(get(a, b, c, d), 0); ans = ans + make_pair(0, get(e, f, g, h)); ans = ans - make_pair(get(A, B, C, D), 0);
		print(ans.first, ' '); print(ans.second, '\n');
	}
	return 0;
}