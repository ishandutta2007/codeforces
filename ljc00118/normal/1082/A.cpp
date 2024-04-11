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

ll T, n, x, y, d;

int main() {
	read(T); while(T--) {
		read(n); read(x); read(y); read(d);
		ll ans = 0x7fffffffffff, qwq = ans;
		if((y - x) % d == 0) ans = abs((y - x) / d);
		if((n - y) % d == 0) ans = min(ans, (n - x - 1 + d) / d + (n - y) / d);
		if((y - 1) % d == 0) ans = min(ans, (x - 1 - 1 + d) / d + (y - 1) / d);
		if(ans == qwq) print(-1, '\n'); else print(ans, '\n');
	}
	return 0;
}