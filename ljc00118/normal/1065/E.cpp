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

const int N = 234567, P = 998244353;

int a[N];
int n, m, A, ans = 1;

inline int mul(int x, int y) { 
	return (int)((ll)x * y % P); 
}

inline void add(int &x, int y) {
	x += y;
	if(x >= P) x -= P;
}

inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

inline int inv(int x) {
	return fpow(x, P - 2);
}

const int inv2 = inv(2);

int main() {
	read(n); read(m); read(A);
	for(register int i = 1; i <= m; i++) read(a[i]);
	sort(a + 1, a + m + 1);
	for(register int i = 1; i <= m; i++) {
		int len = a[i] - a[i - 1], tmp = fpow(A, len);
		ans = mul(ans, mul(tmp, tmp + 1));
		ans = mul(ans, inv2);
	}
	ans = mul(ans, fpow(A, n - a[m] - a[m]));
	cout << ans << endl;
	return 0;
}