#include <bits/stdc++.h>
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

long long n, cnt, ans;

ll calc(ll x) {
	ll ans = 0;
	while(x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int main() {
	cin >> n;
	ll now = 9;
	while(n >= now) {
		ans += 9;
		n -= now;
		now *= 10; 
	}
	ans += calc(n);
	cout << ans << endl;
	return 0;
}