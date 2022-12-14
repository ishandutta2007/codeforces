#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005, MAXM = 2005;

int n, m, p, ppl[MAXN], key[MAXM];

int main(){
	int i, j, mx, ans = 2000000000;
	scanf("%d%d%d", &n, &m, &p);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &ppl[i]);
	sort(ppl + 1, ppl + 1 + n);
	for(i = 1; i <= m; ++ i)
		scanf("%d", &key[i]);
	sort(key + 1, key + 1 + m);
	for(i = 1; i + n - 1 <= m; ++ i){
		for(j = mx = 0; j < n; ++ j)
			mx = max(mx, abs(ppl[j + 1] - key[i + j]) + abs(key[i + j] - p));
		ans = min(ans, mx);
	} printf("%d\n", ans);
	return 0;
}