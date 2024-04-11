#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, p[1003], tp[1003], ans = 2147483647;
char v[1003][5];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &p[i]); 
		scanf("%s", v[i] + 1);
        if (!v[i][2]) v[i][2] = v[i][1];
        if (!v[i][3]) v[i][3] = v[i][2];
        sort(v[i] + 1, v[i] + 4);
	}
	int x;
	for(int i=1; i<=n; i++) {
		x = 0;
		if(v[i][1] == 'A') {
			x += p[i];
			int tmp1 = p[i];
			p[i] = 0;
			for(int j=1; j<=n; j++) {
				if(v[j][1] == 'B' || v[j][2] == 'B' || v[j][3] == 'B') {
					x += p[j];
					int tmp2 = p[j];
					p[j] = 0;
					for(int k = 1; k <= n; k++) {
						if(v[k][3] == 'C') {
							ans = min(ans, x + p[k]);
						}
					}
					p[j] = tmp2;
					x -= p[j];
				}
			}
			p[i] = tmp1;
			x -= p[i];
		}
	}
	printf("%d", ans == 2147483647 ? -1 : ans);
}