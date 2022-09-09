#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

int a[N], b[N];
int n, ans = -1;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int x = -1; x <= 1; x++) {
		for(int y = -1; y <= 1; y++) {
			b[1] = a[1] + x, b[2] = a[2] + y;
			int tmp = abs(x) + abs(y);
			int cha = b[2] - b[1];
			bool ok = 1;
			for(int j = 3; j <= n; j++) {
				if(abs(b[j - 1] - a[j] + cha) >= 2) {
					ok = 0;
					break;
				}
				else {
					tmp += abs(b[j - 1] - a[j] + cha);
					b[j] = b[j - 1] + cha;
				}
			}
			if(ok) {
				if(ans == -1) ans = tmp;
				else if(ans > tmp) ans = tmp;
			}
		}
	}
	printf("%d", ans);
	return 0;
}