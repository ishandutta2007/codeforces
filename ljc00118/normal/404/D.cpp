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

#define P 1000000007
const int N = 1e6 + 5;

int f[N][4][2], a[N];
char c[N];
int n;

int calc(int x) {return x >= P ? x - P : x;}

int main() {
	scanf("%s", c + 1); n = strlen(c + 1);
	for(int i = 1; i <= n; i++) {
		if(c[i] == '*') a[i] = 3;
		else if(c[i] == '?') a[i] = 4;
		else a[i] = c[i] - '0';
	}
	if(a[1] == 4) f[1][0][0] = f[1][1][0] = f[1][2][0] = f[1][3][0] = 1;
	else f[1][a[1]][0] = 1;
	for(int i = 2; i <= n; i++) {
		if(a[i] == 4) {
			f[i][3][0] = calc(calc(f[i - 1][3][0] + f[i - 1][2][1]) + f[i - 1][1][0]);
			f[i][2][1] = f[i - 1][3][0]; f[i][1][1] = f[i - 1][3][0];
			f[i][1][0] = calc(f[i - 1][1][1] + f[i - 1][0][0]);
			f[i][0][0] = calc(f[i - 1][1][1] + f[i - 1][0][0]);
		}
		if(a[i] == 3) f[i][3][0] = calc(calc(f[i - 1][3][0] + f[i - 1][2][1]) + f[i - 1][1][0]);
		if(a[i] == 2) f[i][2][1] = f[i - 1][3][0];
		if(a[i] == 1) f[i][1][1] = f[i - 1][3][0], f[i][1][0] = calc(f[i - 1][1][1] + f[i - 1][0][0]);
		if(a[i] == 0) f[i][0][0] = calc(f[i - 1][1][1] + f[i - 1][0][0]);
	}
	/*for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 3; j++){
			for(int k = 0; k <= 1; k++) {
				fprintf(stderr, "f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
			}
		}
	}*/
	cout << calc(f[n][0][0] + calc(f[n][1][1] + f[n][3][0])) << endl;
	return 0;
}