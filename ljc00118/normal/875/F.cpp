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

struct ele {
	int x, y, val;
	bool operator < (const ele A) const { return val > A.val; } 
}a[N];

int f[N], used[N];
int n, m, ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) f[i] = i;
	for(register int i = 1; i <= m; i++) {
		read(a[i].x); read(a[i].y); read(a[i].val); 
	}
	sort(a + 1, a + m + 1);
	for(register int i = 1; i <= m; i++) {
		if(find(a[i].x) != find(a[i].y) && (!used[find(a[i].x)] || !used[find(a[i].y)])) {
			used[find(a[i].y)] |= used[find(a[i].x)];
			f[find(a[i].x)] = find(a[i].y);
			ans += a[i].val;
		} else if(!used[find(a[i].x)]) {
			ans += a[i].val;
			used[find(a[i].x)] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}