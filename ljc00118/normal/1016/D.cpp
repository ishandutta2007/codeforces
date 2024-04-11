#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; bool fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const int N = 100 + 10;

ll f[N][N];
ll a[N], b[N];
ll na[N], nb[N];
int n, m;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
	for(int i = 0; i <= 31; i++) {
		for(int j = 1; j <= n; j++) na[j] = (a[j] & (1 << i));
		for(int j = 1; j <= m; j++) nb[j] = (b[j] & (1 << i));
		for(int j = 1; j <= n; j++) {
			int cnt = 0; bool ok;
			for(int k = 1; k <= m; k++) if(nb[k]) cnt++;
			cnt = cnt / 2 * 2; if(na[j]) cnt++;
			for(int k = 1; k <= m; k++) if(nb[k] && cnt) cnt--, nb[k] = 0, f[j][k] ^= (1 << i);
			if(cnt) nb[1] = 1 - nb[1], f[j][1] ^= (1 << i);
		}
		bool ok = 1;
		for(int j = 1; j <= m; j++) if(nb[j]) ok = 0;
		if(!ok) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			printf("%d ", (int)f[i][j]);
		}
		printf("\n");
	}
	return 0;
}