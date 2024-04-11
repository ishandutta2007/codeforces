#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

int a[N], b[N], g[300], f[300];
bool used[266];
int n, p;

int main() {
	scanf("%d %d", &n, &p);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(used[a[i]] == 1) {
			b[i] = g[a[i]];
		}
		else {
			int tmp = a[i];
			for(int j = a[i]; j >= max(0, a[i] - p + 1); j--) {
				if(used[j] == 1) {
					if(a[i] - j + 1 + f[j] <= p) tmp = g[j];
					break;
				}
				tmp = j;
			}
			for(int j = tmp; j <= a[i]; j++) {
				used[j] = 1;
				g[j] = tmp;
			}
			f[a[i]] = a[i] - tmp;
			b[i] = g[a[i]];
		}
	}
	for(int i = 1; i <= n; i++) printf("%d ", b[i]);
	return 0;
}