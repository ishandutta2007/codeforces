#include <bits/stdc++.h>
#define int long long
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

const int N = 4e5 + 5;

int a[N], b[N];
int n;

#undef int
int main() {
#define int long long
	read(n);
	for(register int i = 1; i <= n / 2; i++) read(b[i]);
	a[1] = 0; a[n] = b[1];
	for(register int i = 2; i <= n / 2; i++) {
		int wxw = a[i - 1];
		wxw = max(wxw, b[i] - a[n - i + 2]);
		a[i] = wxw; a[n - i + 1] = b[i] - wxw;
	}
	for(register int i = 1; i <= n; i++) print(a[i], i == n ? '\n' : ' ');
	return 0;
}