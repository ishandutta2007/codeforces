#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)


#define N 2333

int n, m;
int a[N][N], b[N][N];
int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			read(a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			read(b[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int c = 0;
		for (int j = 1; j <= m; j++) {
			c ^= a[i][j] ^ b[i][j];	
		}
		if (c) {
			cout << "No" << endl;
			return 0;
		}
	}
	
	for (int j = 1; j <= m; j++) {
		int c = 0;
		for (int i = 1; i <= n; i++) {
			c ^= a[i][j] ^ b[i][j];	
		}
		if (c) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}