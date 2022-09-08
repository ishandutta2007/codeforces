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

const int N = 2e5 + 5, md = 998244353;

char c[N];
int cnt[23333];
int n, cut1 = -1, cut2 = -1;

inline int mul(int x, int y) { return (ll)x * y % md; }

int main() {
	read(n); scanf("%s", c + 1);
	for(register int i = 2; i <= n; i++) if(c[i] != c[i - 1]) { cut1 = i - 1; break; }
	for(register int i = n - 1; i >= 1; i--) if(c[i] != c[i + 1]) { cut2 = i + 1; break; }
	if(cut1 == -1) cout << (ll)n * (n - 1) / 2 % md << endl;
	else if(c[1] == c[n]) cout << mul(cut1 + 1, n - cut2 + 2) << endl;
	else cout << cut1 + 1 + n - cut2 + 2 - 1 << endl;
	return 0;
}