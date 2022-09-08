#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Forr(i, a, b) for(register int i = a; i >= b; i--)
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

const int N = 3e5 + 5;

struct ele {
	ll t, w;
	bool operator < (const ele A) const { return t > A.t; }
}a[N];

priority_queue < ll, vector <ll>, greater <ll> > Q;
int ans = N + 1, n;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i].t), read(a[i].w);
	sort(a + 2, a + n + 1); int now = 2, sum = 0;
	while(now <= n && a[now].t > a[1].t) Q.push(a[now].w - a[now].t + 1ll), now++; ans = now - 1;
	while(a[1].t > 0 && !Q.empty()) {
		ll tmp = Q.top(); Q.pop();
		if(tmp > a[1].t) break;
		a[1].t -= tmp; sum++;
		while(now <= n && a[now].t > a[1].t) Q.push(a[now].w - a[now].t + 1ll), now++;
		ans = min(ans, now - 1 - sum);
	}
	cout << ans << endl;
	return 0;
}