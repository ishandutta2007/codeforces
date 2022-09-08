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

int cnt[1005], qwq[1005];
int n, m; ll ans;

int main() {
	read(n); read(m);
	for(register int i = 1; i <= m; i++) qwq[i * i % m]++;
	for(register int i = 0; i < m; i++) cnt[i] = qwq[i] * (n / m);
	int maxn = n % m;
	for(register int i = 1; i <= maxn; i++) cnt[i * i % m]++;
	ans += (ll)cnt[0] * cnt[0];
	for(register int i = 1; i <= m; i++) ans += (ll)cnt[i] * cnt[m - i];
	cout << ans << endl;
	return 0;
}