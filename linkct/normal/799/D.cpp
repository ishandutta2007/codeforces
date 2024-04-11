#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL INF = 1e15;
const int MAXN = 100005;

int dp[MAXN], a, b, w, h, n, ext[MAXN]; bool used[MAXN];

inline void trace(int x){
	for(; x > 1; x /= ext[dp[x]])
		used[dp[x]] = true;
}
inline bool check(int x, int c, int d){
	LL cur, best; int besti, i, j, multi, bestj;
	memset(dp, 0, sizeof(dp));
	multi = (c - 1) / w + 1;
	//w -> c, h -> d
	dp[1] = -1;
	for(i = 1; i <= x; ++ i)
		for(j = multi / ext[i]; j; -- j)
			if(dp[j] && !dp[j * ext[i]])
				dp[j * ext[i]] = i;
	memset(used, false, sizeof(used));
	if(dp[multi]){
		trace(multi);
		for(i = 1, cur = h; i <= x && cur < d; ++ i)
			if(!used[i]) cur *= ext[i];
		return cur >= d;
	}
	best = INF, besti = 0;
	for(i = 1; i < multi; ++ i){
		if(!dp[i]) continue;
		for(j = x; j > dp[i]; -- j)
			if(LL(i) * ext[j] >= multi)
				break;
		if(j > dp[i] && LL(i) * ext[j] < best){
			best = LL(i) * ext[j];
			besti = i, bestj = j;
		}
	}
	if(besti){
		trace(besti); used[bestj] = true;
		for(i = 1, cur = h; i <= x && cur < d; ++ i)
			if(!used[i]) cur *= ext[i];
		return cur >= d;
	} return false;
}
inline bool check(int x){
	return check(x, a, b) || check(x, b, a);
}
int main(){
	int i, l, r, mid;
	scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
	for(i = 1; i <= n; ++ i) scanf("%d", &ext[i]);
	sort(ext + 1, ext + 1 + n);
	reverse(ext + 1, ext + 1 + n);
	l = 0, r = min(n, 34);
	while(l < r){
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	} printf("%d\n", check(r) ? r : -1);
	return 0;
}