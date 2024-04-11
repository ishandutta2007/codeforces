#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
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

int a[300005];
char c[300005];
int n, x, y, cnt1, cnt2;

int main() {
	read(n); read(x); read(y); scanf("%s", c + 1);
	for(register int i = 1; i <= n; i++) a[i] = c[i] - '0';
	cnt1 = (a[1] == 0); cnt2 = (a[1] == 1);
	for(register int i = 2; i <= n; i++) {
		if(a[i] == 0 && a[i] != a[i - 1]) ++cnt1;
		if(a[i] == 1 && a[i] != a[i - 1]) ++cnt2;
	}
	int cnt = cnt1;
	if(!cnt) cout << 0 << endl;
	else {
		if(x < y) cout << (ll)x * (cnt - 1) + y << endl;
		else cout << (ll)cnt * y << endl;
	}
	return 0;
}