# include <bits/stdc++.h>
using namespace std;

int get_log(int n) {
	int res = 0;
	while(n) n = n >> 1, res ++;
	return res;
}

int main() {
	int n; scanf("%d", &n);
	int ans = get_log(n);
	printf("%d\n", ans);
	return 0;
}