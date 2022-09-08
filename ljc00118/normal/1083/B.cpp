#include <bits/stdc++.h>
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

const int N = 5e5 + 5;

char a[N], b[N];
ll ans, now, all, Pow = 1;
int n, k, ok = 0;

int main() {
	read(n); read(k); scanf("%s%s", a + 1, b + 1);
	if(a[1] == 'a') now++; if(b[1] == 'b') now++;
	if(now >= k) {
		cout << (ll)k * n << endl;
		return 0;
	}
	if(a[1] != b[1]) ok = 1;
	ans = now;
	int left = a[1], right = b[1];
	for(register int i = 2; i <= n; i++) {
		now = 0;
		all <<= 1; now += all;
		bool last = ok;
		ok |= (a[i] != b[i]); 
		if(last) {
			if(a[i] == 'a') now += 2, all += ok;
			else now++;
			if(b[i] == 'b') now += 2, all += ok;
			else now++;
		} else {
			if(a[i] == 'a') now++;
			if(b[i] == 'b') now++;
		}
		if(now >= k) {
			cout << (ll)k * (n - i + 1) + ans << endl;
			return 0;
		} else ans += now;
	}
	print(ans, '\n');
	return 0;
}