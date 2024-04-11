#include <bits/stdc++.h>
using namespace std;
const int MAXL = 100005;

int n, m, f[MAXL], dp[MAXL];
char s[MAXL], t[MAXL];

inline void update(int &a, int b){if(a < b) a = b;}
int main(){
	int i, j, k, pre, ans = 0;
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	if(n < m){
		printf("0\n");
		return 0;
	}
	for(i = 2, j = 0; i <= m; ++ i){
		while(j && t[i] != t[j + 1]) j = f[j];
		if(t[i] == t[j + 1]) ++ j;
		f[i] = j;
	}
	memset(dp, 0xbf, sizeof(dp));
	dp[0] = pre = 0;
	for(i = m; i <= n; ++ i){
		for(j = 0; j < m; ++ j)
			if(s[i - j] != '?' && s[i - j] != t[m - j])
				break;
		for(k = f[m]; k && m - k <= j; k = f[k])
			update(dp[i], dp[i - m + k] + 1);
		update(pre, dp[i - m]);
		if(j == m) update(dp[i], pre + 1);
		update(ans, dp[i]);
	} printf("%d\n", ans);
	return 0;
}