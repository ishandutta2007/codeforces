/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
#define read(a) scanf("%d", &a)


int n, m, Q;
int cnt[4097], w[233], W[4097];

int a[4097], b[4097][4097];

bool cmp(int x, int y) {
	return W[x] < W[y];
}

int main() {
	read(n); read(m); read(Q);
	for (int i = 0; i < n; i++) {read(w[i]);}
	for (int i = 1; i <= m; i++) {
		int ch = getchar();
		int x = 0;
		for (int j = 0; j < n; j++) {
			while (ch < '0' || ch > '9') ch = getchar();
			if (ch == '1') x ^= (1 << j);
			ch = getchar();
		}
//		cerr << "=-- " << x << endl;
		cnt[x]++;
	}
	for (int i = 0; i < (1 << n); i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) if ((i >> j) & 1) tmp += w[j];
		W[i] = tmp;
	}
	for (int j = 0; j < (1 << n); j++) a[j] = j;
	sort(a, a + (1 << n), cmp);
//	for (int j = 0; j < (1 << n); j++) cerr << " a "<< a[j] << endl;
	for (int i = 0; i < (1 << n); i++) {
		b[i][0] = cnt[a[0] ^ i];
		for (int j = 1; j < (1 << n); j++) {
			b[i][j] = b[i][j - 1] + cnt[a[j] ^ i];
//			cerr << "- " << i << " " << (a[j] ^ i) << endl;
		}
	}
	for (int i = 1; i <= Q; i++) {
		int ch = getchar();
		int x = 0, y;
		for (int j = 0; j < n; j++) {
			while (ch < '0' || ch > '9') ch = getchar();
			if (ch == '1') x ^= (1 << j);
			ch = getchar();
		}
		x ^= (1 << n ) - 1;
		read(y);
		int l = -1, r = (1 << n) - 1;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (W[a[mid]] <= y) l = mid;
			else r = mid - 1;
		}
	//	cerr << l << endl;
		printf("%d\n", l < 0 ? 0 : b[x][l]);
	}
	
	return 0;
}