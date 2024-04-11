#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5015;

int n, m, a[MAXN], val[MAXN], row[MAXN][MAXN], col[MAXN][MAXN], dp[MAXN];

inline void update(int &u, int v){if(u < v) u = v;}
int main(){
	int i, j, s, ans = 0, cur;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		val[i - 1] = a[i];
	} sort(val, val + n);
	m = unique(val, val + n) - val;
	for(i = 1; i <= n; ++ i){
		a[i] = lower_bound(val, val + m, a[i]) - val;
		if(a[i] && val[a[i] - 1] == val[a[i]] - 1)
			update(dp[i], row[0][a[i] - 1] + 1);
		if(a[i] < m - 1 && val[a[i] + 1] == val[a[i]] + 1)
			update(dp[i], row[0][a[i] + 1] + 1);
		update(dp[i], row[0][val[a[i]] % 7 + m] + 1);
		update(row[0][a[i]], dp[i]);
		update(row[0][val[a[i]] % 7 + m], dp[i]);
	} memset(row[0], 0, sizeof(row[0]));
	for(s = 3; s < n << 1; ++ s){
		for(i = 1; i <= n && i < s; ++ i){
			if((j = s - i) > n || (i == j)) continue;
			if(i > j){
				cur = dp[j] + 1;
				if(a[i] && val[a[i] - 1] == val[a[i]] - 1)
					update(cur, col[a[i] - 1][j] + 1);
				if(a[i] < m - 1 && val[a[i] + 1] == val[a[i]] + 1)
					update(cur, col[a[i] + 1][j] + 1);
				update(cur, col[val[a[i]] % 7 + m][j] + 1);
			}else{
				cur = dp[i] + 1;
				if(a[j] && val[a[j] - 1] == val[a[j]] - 1)
					update(cur, row[i][a[j] - 1] + 1);
				if(a[j] < m - 1 && val[a[j] + 1] == val[a[j]] + 1)
					update(cur, row[i][a[j] + 1] + 1);
				update(cur, row[i][val[a[j]] % 7 + m] + 1);
			}
			update(row[i][a[j]], cur);
			update(row[i][val[a[j]] % 7 + m], cur);
			update(col[a[i]][j], cur);
			update(col[val[a[i]] % 7 + m][j], cur);
			update(ans, cur);
		}
	} printf("%d\n", ans);
	return 0;
}