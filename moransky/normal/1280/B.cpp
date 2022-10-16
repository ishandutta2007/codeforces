#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef long long LL;

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

const int N = 65;

int n, m;

char s[N][N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		read(n); read(m);
		for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
		bool a0 = 1, a1 = 0, a2 = 0, a3 = 0, no = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i][j] == 'A') {
					no = 0;
				}
				if (s[i][j] == 'P') a0 = 0;
			}
		}
		bool f = 1;
		for (int i = 1; i <= m; i++) {
			if (s[1][i] == 'P') f = 0;
		}
		if (f) a1 = 1;
		f = 1;
		for (int i = 1; i <= m; i++) {
			if (s[n][i] == 'P') f = 0;
		}
		if (f) a1 = 1;
		f = 1;
		for (int i = 1; i <= n; i++) {
			if (s[i][1] == 'P') f = 0;
		}
		if (f) a1 = 1;
		f = 1;
		for (int i = 1; i <= n; i++) {
			if (s[i][m] == 'P') f = 0;
		}
		if (f) a1 = 1;
		
		if (s[1][1] == 'A' || s[1][m] == 'A' || s[n][1] == 'A' || s[n][m] == 'A') a2 = 1;
		
		for (int i = 1; i <= n; i++) {
			f = 1;
			for (int j = 1; j <= m; j++) {
				if (s[i][j] == 'P') f = 0;
			}
			if (f) a2 = 1;
		}
		for (int i = 1; i <= m; i++) {
			f = 1;
			for (int j = 1; j <= n; j++) {
				if (s[j][i] == 'P') f = 0;
			}
			if (f) a2 = 1;
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i][j] == 'A') {
					if (i == 1 || i == n || j == 1 || j == m)
						a3 = 1;
				}
			}
		}
			
		if (no) puts("MORTAL");
		else if (a0) puts("0");
		else if (a1) puts("1");
		else if (a2) puts("2");
		else if (a3) puts("3");
		else puts("4");
	}	
	return 0;
}