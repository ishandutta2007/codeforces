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

const int N = 2e5 + 5;

int a[N], b[N], used[N], pre[N];
int n;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]), pre[a[i]] = i;
	for(register int i = 1; i <= n; i++) {
		read(b[i]); int ans = 0; b[i] = pre[b[i]];
		while(!used[b[i]] && b[i]) used[b[i]] = 1, ans++, b[i]--;
		print(ans, ' ');
	}
	return 0;
}