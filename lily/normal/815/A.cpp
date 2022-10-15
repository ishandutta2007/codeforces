/* Never Say Die */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long LL;
typedef double D;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
int ch = 0;
template <class T> inline void read(T &a) {
	bool f = 0; a = 0;
	while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
	if (f) a = -a;
}

#define MAXN 105

int n, m;
int a[MAXN][MAXN], col[MAXN], row[MAXN];

vector <int> R, C;
void row_(int i) {
	row[i]--;
	for (int j = 1; j <= m; j++) col[j] = min(col[j], --a[i][j]);
	R.push_back(i);
}


void col_(int j) {
	--col[j];
	for (int i = 1; i <= n; i++) row[i] = min(row[i], --a[i][j]);
	C.push_back(j);
}


int main() {
	read(n); read(m);
	for (int i = 1; i <= n ;i++)
		for (int j = 1; j <= m; j++) {
			read(a[i][j]);
		}
	for (int i = 1; i <= n; i++) {
		row[i] = 0x3ffffff;
		for (int j = 1; j <= m; j++) {
			row[i] = min(row[i], a[i][j]);	
		}
	}
	for (int j = 1; j <= m; j++) {
		col[j] = 0x3ffffff;
		for (int i = 1; i <= n; i++) {
			col[j] = min(col[j], a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (m > n) {
				while (a[i][j] && row[i]) row_(i);
				while (a[i][j] && col[j]) col_(j);
			}
			else {
				while (a[i][j] && col[j]) col_(j);
				while (a[i][j] && row[i]) row_(i);
			}
			if (a[i][j]) {
				puts("-1");
				return 0;
			}
		}
	}
	printf("%d\n", (int)(R.size() + C.size()));
	for (int i = 0; i < R.size(); i++) printf("row %d\n", R[i]);
	for (int i = 0; i < C.size(); i++) printf("col %d\n", C[i]);

	return 0;
}