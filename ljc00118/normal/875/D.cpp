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

const int N = 2e5 + 5;

map <int, int> pre;
int l[N], r[N], a[N], now[40];
int n; ll ans;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]);
	for(register int i = 1; i <= n; i++) l[i] = 1;
	for(register int i = 1; i <= n; i++) {
		for(register int j = 0; j < 32; j++) {
			if(a[i] & (1 << j)) {
				now[j] = i;
			} else if(now[j]) {
				l[i] = max(l[i], now[j] + 1);
			}
		}
		l[i] = max(l[i], pre[a[i]] + 1);
		pre[a[i]] = i;
	}
	for(register int i = 0; i <= 31; i++) now[i] = n + 1;
	for(register int i = 1; i <= n; i++) r[i] = n;
	for(register int i = n; i >= 1; i--) {
		for(register int j = 0; j < 32; j++) {
			if(a[i] & (1 << j)) {
				now[j] = i;
			} else if(now[j] != n + 1) {
				r[i] = min(r[i], now[j] - 1);
			}
		}
	}
	for(register int i = 1; i <= n; i++) ans += (ll)(i - l[i] + 1) * (r[i] - i + 1);
	cout << (ll)n * (n + 1) / 2 - ans << endl;
	return 0;
}