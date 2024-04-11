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

const int N = 1000 + 10;

int f[N], g[N], len = 0;
char a[N], b[N];
int n, m, q, al, bl;

int main() {
	cin >> n >> m >> q;
	scanf("%s %s", a, b);
	al = strlen(a), bl = strlen(b);
	f[0] = f[1] = 0;
	int tmp = 0;
	for(int i = 1; i < bl; i++) {
		while(tmp && b[i] != b[tmp]) tmp = f[tmp];
		f[i + 1] = (b[i] == b[tmp] ? ++tmp : 0);
	}
	tmp = 0;
	for(int i = 0; i < al; i++) {
		while(tmp && a[i] != b[tmp]) tmp = f[tmp];
		if(a[i] == b[tmp]) tmp++;
		if(tmp == bl) g[++len] = i - bl + 2;
	}
	for(int i = 1; i <= q; i++) {
		int l = 1, r = len;
		int a, b;
		scanf("%d %d", &a, &b);
		b -= (m - 1);
		while(l < r) {
			int mid = (l + r) >> 1;
			if(g[mid] < a) l = mid + 1;
			else r = mid;
		}
		if(g[l] < a || g[l] > b) {
			printf("0\n");
			continue;
		}
		int tmp = l;
		l = 1, r = len;
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(g[mid] > b) r = mid - 1;
			else l = mid;
		}
		printf("%d\n", r - tmp + 1);
	}
	return 0;
}