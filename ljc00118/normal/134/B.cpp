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

int calc(int x, int y) {
	if(x == 1 && y == 0) return -1;
	if(!y) return 1e9;
	return x / y + calc(y, x % y);
}

int n, ans = INT_MAX;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) ans = min(ans, calc(n, i));
	cout << ans << endl;
	return 0;
}