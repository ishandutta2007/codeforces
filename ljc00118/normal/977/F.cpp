#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;

map <int, int> f, weizhi;
int a[N], from[N], An[N];
int n;
int ans = 0, ansnum = 0, len = 0;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(f[a[i]] == 0) {
			f[a[i]] = f[a[i] - 1] + 1;
			from[i] = weizhi[a[i] - 1];
			weizhi[a[i]] = i;
		}
		else if(f[a[i] - 1] + 1 > f[a[i]]) {
			f[a[i]] = f[a[i] - 1] + 1;
			from[i] = weizhi[a[i] - 1];
			weizhi[a[i]] = i;
		}
		if(f[a[i]] > ans) {
			ans = f[a[i]];
			ansnum = i;
		}
	}
	printf("%d\n", ans);
	while(ansnum) {
		An[++len] = ansnum;
		ansnum = from[ansnum];
	}
	for(int i = ans; i >= 1; i--) printf("%d ", An[i]);
	return 0;
}