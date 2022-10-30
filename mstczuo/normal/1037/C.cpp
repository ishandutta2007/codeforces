# include <bits/stdc++.h>
using namespace std;

char a[1000010];
char b[1000010];
int main() {
	int n, ans = 0;
	scanf("%d%s%s", &n, a, b);
	for(int i = 0; i < n; ++i) ans += (a[i] != b[i]);
	for(int i = 0; i < n; ++i) {
		if(a[i] == b[i]) continue;
		if(a[i] == b[i+1] && b[i] == a[i+1]) {
			ans--; i++;
		}
	}
	printf("%d\n", ans);
	return 0;
}