# include <bits/stdc++.h>
using namespace std;

int f[704][704];
int a[704];
bool g[704][704];

int gcd(int a,int b) {
	for(int t; b; t = a, a = b, b = t % a);
	return a;
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j < i; ++j) 
			if(gcd(a[i], a[j]) > 1) g[i][j] = g[j][i] = true;
	for(int i = 1; i <= n; ++i) {
		if(g[i][i-1]) f[i][i] |= 1;
		if(g[i][i+1]) f[i][i] |= 2;
	}
	for(int len = 2; len < n; ++len) {
		for(int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			for(int k = i; k <= j; ++k) {
				if((k == i || (f[i][k-1] & 2)) && (k == j || (f[k+1][j] & 1))) {
					if(g[k][i-1]) f[i][j] |= 1;
					if(g[k][j+1]) f[i][j] |= 2;
					if(f[i][j] == 3) break;
				}
			}
		}
	}
	bool flag = false;
	for(int k = 1; k <= n; ++k)
		if(k == 1 || (f[1][k-1] & 2)) if(k == n || (f[k+1][n] & 1))
			flag = true;
	puts(flag ? "Yes" : "No");
	return 0;
}