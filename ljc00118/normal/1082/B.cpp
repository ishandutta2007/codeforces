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

struct ele {
	int l, r;
	ele (int a = 0, int b = 0) : l(a), r(b) {}
}p[N];

char c[N]; bool vis[N];
int n, ans = 0, len, cnt;

int main() {
	read(n); scanf("%s", c + 1);
	for(register int i = 1; i <= n; i++) if(c[i] == 'G') cnt++;
	for(register int i = 1; i <= n; i++) if(c[i] == 'G' && !vis[i]) {
		register int j;
		for(j = i; c[j] == 'G' && j <= n; j++) vis[j] = 1; j--;
		p[++len] = ele(i, j); ans = max(ans, j - i + 1);
	}
	if(len > 1) ans++;
	for(register int i = 1; i < len; i++) if(p[i].r + 2 == p[i + 1].l) { if(len > 2) ans = max(ans, p[i + 1].r - p[i].l + 1); else ans = max(ans, p[i + 1].r - p[i].l); }
	cout << ans << endl;
	return 0;
}