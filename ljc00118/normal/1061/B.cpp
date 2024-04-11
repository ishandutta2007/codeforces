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

int a[100005];
int n, m; ll ans;

bool cmp(int x, int y) { return x > y; }

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) read(a[i]), ans += (ll)a[i];
	sort(a + 1, a + n + 1, cmp); int now = a[1];
	for(register int i = 1; i <= n; i++) {
		if(a[i] >= now) ans--, now--;
		else ans -= now - a[i] + 1, now = a[i] - 1;
	}
	if(now > 0) ans -= now;
	cout << ans << endl;
	return 0;
}