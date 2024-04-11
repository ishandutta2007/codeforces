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

const int N = 1e5 + 5;

int a[N], s[N];
int n, m, ans;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) read(a[i]); a[++n] = m;
	for(int i = 1; i <= n; i += 2) ans += a[i] - a[i - 1];
	s[1] = a[1];
	for(int i = 3; i <= n; i += 2) s[i - 1] = s[i - 2], s[i] = s[i - 1] + a[i] - a[i - 1]; if(!s[n]) s[n] = s[n - 1];
	ans = s[n];
	for(int i = 0; i <= n; i += 2) {
		if(i && a[i] != a[i - 1] + 1) ans = max(ans, s[n] + (a[n] - a[i]) - (s[n] - s[i]) * 2 + 1);
		if(i != n && a[i] != a[i + 1] - 1) ans = max(ans, s[n] + (a[n] - a[i]) - (s[n] - s[i]) * 2 + 1);
	}
	for(int i = 1; i <= n; i += 2) {
		if(i && a[i] != a[i - 1] + 1) ans = max(ans, s[n] + (a[n] - a[i]) - (s[n] - s[i]) * 2 - 1);
//		fprintf(stderr, "i = %d, ans = %d\n", i, ans);
		if(i != n && a[i] != a[i + 1] - 1) ans = max(ans, s[n] + (a[n] - a[i]) - (s[n] - s[i]) * 2 - 1);
	}
	cout << ans << endl;
	return 0;
}