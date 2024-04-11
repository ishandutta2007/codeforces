#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const int N = 3005;

int a[N][N], b[N], len[N];
int n, m, Len, t = 0;
ll ans = 1e18, now;

bool cmp(int x, int y) {return x > y;}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int x, y; read(x); read(y);
		len[x]++; a[x][len[x]] = y;
		if(x == 1) t++;
	}
	for(int i = 1; i <= m; i++) if(len[i]) sort(a[i] + 1, a[i] + len[i] + 1, cmp);
	for(int i = 0; i <= n - 1; i++) {
		now = 0; Len = 0; int x = 0;
		for(int j = 2; j <= m; j++) {
			for(int k = len[j]; k > i; k--) now += (ll)a[j][k], x++;
			for(int k = min(len[j], i); k >= 1; k--) b[++Len] = a[j][k];
		}
		sort(b + 1, b + Len + 1);
		for(int j = 1; j <= i - (t + x) + 1; j++) now += (ll)b[j];
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}