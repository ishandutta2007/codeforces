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

const int N = 1005;

pair <int, int> f[N * N];
int x[N], y[N], _x[N], _y[N];
int n, len, ans;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(x[i]), read(y[i]);
	for(register int i = 1; i <= n; i++) read(_x[i]), read(_y[i]);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= n; j++) {
			f[++len] = make_pair(x[i] + _x[j], y[i] + _y[j]);
		}
	}
	sort(f + 1, f + len + 1); int ans = 1;
	if(ans == n) { cout << f[2 - 1].first << " " << f[2 - 1].second << endl; return 0; }
	for(register int i = 2; i <= len; i++) {
		if(f[i] == f[i - 1]) ans++; else ans = 1;
		if(ans == n) { cout << f[i].first << " " << f[i].second << endl; return 0; }
	}
	return 0;
}