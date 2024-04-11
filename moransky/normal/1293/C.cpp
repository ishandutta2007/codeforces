#include <cstdio>
#include <iostream>
using namespace std;
const int N = 200005;
int n, Q, g[2][N];
bool f[N];
int cnt = 0;
int main() {
	scanf("%d%d", &n, &Q);
	while(Q--) {
		int r, c;
		scanf("%d%d", &r, &c);
		r--;
		if (g[r][c] == 1) {
			// 
			if (c > 1 && !g[r][c - 1] && f[c - 1]) {
				f[c - 1] = false;
				cnt--; 
			} 

			if(c < n && !g[r][c + 1] && f[c]) {
				f[c] = false; cnt--;
			}

			g[r][c] = 0;
		} else {
			// 
			if(c > 1 && (g[!r][c - 1] || g[!r][c]) && !f[c - 1]) {
				f[c - 1] = true, cnt++;
			}

			if(c < n && g[!r][c + 1] && !f[c]) {
				f[c] = true, cnt++;
			}
			g[r][c] = 1;
		}
		puts(cnt ? "No" : "Yes");
	}
	return 0;
}