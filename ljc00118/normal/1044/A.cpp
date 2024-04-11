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

const int N = 1e5 + 5;

int a[N], b[N];
int n, m, len, ans, minn = 0x7fffffff;

int main() {
	read(n); read(m); minn = m;
	for(register int i = 1; i <= n; i++) read(a[i]);
	for(register int i = 1; i <= m; i++) {
		int x, y, z;
		read(x); read(y); read(z);
		if(x != 1) continue;
		if(y == 1e9) ans++;
		else b[++len] = y;
	}
	sort(a + 1, a + n + 1); sort(b + 1, b + len + 1); a[++n] = 1e9;
	for(register int i = 1; i <= n + 1; i++) minn = min(minn, (int)(ans + len - (lower_bound(b + 1, b + len + 1, a[i]) - b) + i));
	cout << minn << endl;
	return 0;
}