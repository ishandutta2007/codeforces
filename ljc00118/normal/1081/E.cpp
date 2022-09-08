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

const int N = 1e5 + 5;

vector <ll> wxw; 
ll a[N], s[N];
int n;

int main() {
	read(n);
	for(register int i = 1; i <= (n >> 1); i++) read(a[i << 1]);
	for(register int i = 2; i <= n; i += 2) {
		ll now = s[i - 2]; wxw.clear(); bool ok = 0;
		for(ll j = 1; j * j <= a[i]; j++) if(a[i] % j == 0) wxw.push_back(j);
		for(register int j = wxw.size() - 1; j >= 0; j--) {
			ll x = wxw[j], y = a[i] / x;
			if((x + y) & 1) continue;
			ll last = (y - x) >> 1;
			if(last * last > now) {
				a[i - 1] = last * last - now;
				if(a[i - 1] > (ll)1e13) continue;
				ok = 1; s[i] = s[i - 2] + a[i - 1] + a[i];
				break;
			}
		}
		if(!ok) { printf("No\n"); return 0; }
	}
	printf("Yes\n");
	for(register int i = 1; i <= n; i++) print(a[i], i == n ? '\n' : ' '); 
	return 0;
}

// Rotate Flower Round.