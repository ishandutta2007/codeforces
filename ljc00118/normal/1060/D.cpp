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

const int N = 1e6 + 5;

ll a[N], b[N], ans;
int n;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) read(a[i]), read(b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++) ans += max(a[i], b[i]);
	cout << ans + n << endl; 
	return 0;
}