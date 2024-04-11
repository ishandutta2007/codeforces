#include<bits/stdc++.h>
using namespace std;

const int N = 2000 + 10;

int a[N][N], s[N];
int n, m;

inline int read() {
	int f = 0, fu = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') fu = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		f = (f << 3) + (f << 1) + c - 48;
		c = getchar();
	}
	return f * fu;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char c = getchar();
			while(c < '0' || c > '9') c = getchar();
			if(c == '1') {
				a[i][j] = 1;
				s[j]++;
			}
			else a[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		bool ok = 1;
		for(int j = 1; j <= m; j++) {
			if(s[j] <= a[i][j]) {
				ok = 0;
				break;
			}
		}
		if(ok) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}