#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef unsigned long long ll;

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

const ll INF = 9223372036854775807ll;

ll n, k, t[100];
int T;

bool check(ll x, ll y) {
	double a = (double)x / INF;
	double b = (double)y / INF;
	return (a * b - 1e-4) >= 1;
}

int main() {
	read(T); t[0] = 0; t[1] = 1;
	for(register int i = 2; i <= 31; i++) t[i] = t[i - 1] + (1ll << i - 1) * (1ll << i - 1);
	while(T--) {
		read(n); read(k); int ans = -1;
		if(n >= 32 || t[n - 1] + 1 >= k) {
			printf("YES %d\n", n - 1);
			continue;
		}
		ll now = 1, nowcan = t[n - 1], cnt = 1;
		for(register int i = 2; i <= n + 1 && now <= k && i <= 31; i++) {
			if(k - now <= nowcan) {
				ans = n - i + 1;
				break;
			}
			if(i == n + 1) break;
//			cout << now << " " << nowcan << " " << cnt << endl;
			now += (cnt + 2ll);
			cnt = (1ll << i + 1) - 3;
			if(check(t[n - i], cnt)) nowcan = INF;
			else nowcan += t[n - i] * cnt;
		}
		if(ans != -1) printf("YES %d\n", ans);
		else printf("NO\n");
	}
	return 0;
}