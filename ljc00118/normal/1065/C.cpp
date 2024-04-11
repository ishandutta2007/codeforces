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

const int N = 234567;

ll a[N];
ll n, k, maxn, ans;

bool cmp(ll x, ll y) { return x > y; }

int main() {
	read(n); read(k);
	for(register int i = 1; i <= n; i++) read(a[i]), maxn = max(maxn, a[i]);
	sort(a + 1, a + n + 1, cmp); ll now = 1, sum = 0;
	for(register int i = maxn; i >= 1; i--) {
		while(a[now] == i && now != n + 1) now++;
		if(now == n + 1) break;
		sum += now - 1; if(sum > k) ans++, sum = now - 1;
	} if(sum) ans++; cout << ans << endl;
	return 0;
}