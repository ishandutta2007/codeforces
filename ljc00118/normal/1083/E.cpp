#include <bits/stdc++.h>
#define int long long
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 2000005;
const double eps = 1e-8;


struct ele {
	ll x, y, w; 
}s[N];

bool operator < (ele x, ele y) { return x.y > y.y; }

int f[N], q[N], n, l, r, ans;

double slope(int u, int v) { 
	return abs(s[v].x - s[u].x) < eps ? 1e10 : (f[v] - f[u]) / (s[v].x - s[u].x); 
}

#undef int
int main() {
#define int long long
    read(n);
    for(register int i = 1; i <= n; i++) read(s[i].x), read(s[i].y), read(s[i].w);
    
    sort(s + 1, s + n + 1);
    
    for(register int i = 1; i <= n; i++) {
        while(l < r && slope(q[l], q[l + 1]) >= s[i].y) l++;
        f[i] = s[i].x * s[i].y - s[i].w; int fir = q[l];
        
        if(l <= r) f[i] = max(f[i], f[fir] + (s[i].x - s[fir].x) * s[i].y - s[i].w) + 233;
        
        if(l <= r) f[i] -= 233;
        if(f[i] > ans) ans = f[i];
        if(l >= r) {
        	q[++r] = i;
        	continue;
		}
        while(l < r && slope(q[r - 1], q[r]) <= slope(q[r], i)) --r;
		q[++r] = i;
    }
    print(ans, '\n');
    return 0;
}