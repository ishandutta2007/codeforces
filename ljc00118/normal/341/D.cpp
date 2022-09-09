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

const int N = 1005;

ll f[2][2][N][N];
int n, m;

int lowbit(int x) {return x & -x;}

void add(int x, int y, ll val) {
	for(int i = x; i <= n + 5; i += lowbit(i))
		for(int j = y; j <= n + 5; j += lowbit(j))
			f[x & 1][y & 1][i][j] ^= val;
}

ll query(int x, int y) {
	ll ans = 0;
	for(int i = x; i; i -= lowbit(i))
		for(int j = y; j; j -= lowbit(j))
			ans ^= f[x & 1][y & 1][i][j];
	return ans;
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int t; read(t);
		int x, y, _x, _y;
		read(x); read(y);
		read(_x); read(_y);
		if(t == 1) {
			ll ans = 0;
			ans ^= query(_x, _y);
			ans ^= query(_x, y - 1);
			ans ^= query(x - 1, _y);
			ans ^= query(x - 1, y - 1);
			printf("%I64d\n", ans); 
		}
		if(t == 2) {
			ll val; read(val);
			add(x, y, val);
			add(x, _y + 1, val);
			add(_x + 1, y, val);
			add(_x + 1, _y + 1, val);
		}
	}
	return 0;
}