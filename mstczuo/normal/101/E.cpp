# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

const int maxn = 20000 + 120;

int a[maxn], b[maxn];
long long f[2][maxn];
int g[maxn/2][maxn/32];


char ans[maxn * 2];

void DP(int n,int m,int p,int flag) {
	f[0][0] = (a[0] + b[0]) % p;
	for(int j = 1; j < m; ++j) 
		f[0][j] = f[0][j-1] + (a[0] + b[j]) % p;
	for(int i = 1; i < n; ++i) {
		f[i&1][0] = f[(i-1)&1][0] + (a[i] + b[0]) % p; 
		if(flag) {
			if(i >= n / 2) g[i-n/2][0] |= 1;
		} else {
			if(i < n / 2) g[i][0] |= 1;
		}
		for(int j = 1; j < m; ++j) {
			f[i&1][j] = max(f[(i-1)&1][j], f[i&1][j-1]) + (a[i] + b[j]) % p;
			if(flag) {
				if(i >= n / 2) g[i-n/2][j>>5] |= (f[(i-1)&1][j] > f[i&1][j-1]) ? (1<<(j&31)) : 0;
			} else {
				if(i < n / 2) g[i][j>>5] |= (f[(i-1)&1][j] > f[i&1][j-1]) ? (1<<(j&31)) : 0;
			}
		}
	}
}

int main() {
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int j = 0; j < m; ++j) scanf("%d", &b[j]);

	DP(n, m, p, 1);

	cout << f[(n-1)&1][m-1] << endl;

	int i = n - 1, j = m - 1;
	while(i >= n / 2 && i + j) {
		if(g[i - n / 2][j>>5] & (1<<(j&31))) {
			ans[i + j] = 'C';
			--i;
		} else {
			ans[i + j] = 'S';
			--j;
		}
	}

	memset(g, 0, sizeof(g));
	DP(n, m, p, 0);

	while(i + j) {
		if(g[i][j>>5] & (1<<(j&31))) {
			ans[i + j] = 'C';
			--i;
		} else {
			ans[i + j] = 'S';
			--j;
		}
	}

	puts(ans+1);
}