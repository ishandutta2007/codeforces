# include <bits/stdc++.h>
using namespace std;

char a[200010];
int main() {
	scanf("%s", a);
	int n = strlen(a);
	for(int i = 0; i < n; ++i) 
		a[i + n] = a[i];
	int ans = 1;
	for(int i = 0, j; i < n << 1; i = j) {
		for(j = i; j < n << 1; j++) 
			if(j > i && a[j] == a[j-1]) break;
		ans = max(ans, j - i);
	}
	ans = min(ans, n);
	printf("%d\n", ans);
	return 0;
}