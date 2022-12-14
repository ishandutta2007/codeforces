#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 100005, MAXV = 65;

int n, cur[MAXV], ncur[MAXV], cnt[MAXV], ncnt[MAXV]; LL a[MAXN];

inline bool check(int x){
	int i;
	memset(cur, 0, sizeof(cur));
	memcpy(ncur, ncnt, sizeof(ncur));
	cur[0] = x, ncur[0] = cnt[0] - cur[0];
	for(i = 1; i < 40; ++ i){
		ncur[i] += max(cnt[i] - cur[i - 1], 0);
		cur[i] = min(cur[i - 1], cnt[i]);
	}
	for(i = 39; i >= 0; -- i){
		ncur[i] += ncur[i + 1];
		if(ncur[i] > cur[i]) return false;
	} return true;
}
int main(){
	int i, j, l, r, mid;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%I64d", &a[i]);
	for(i = 1, j = 0; i <= n; ++ i){
		while((1LL << j) < a[i]) ++ j;
		if((1LL << j) == a[i]) ++ cnt[j];
		else ++ ncnt[j - 1];
	} l = 1, r = cnt[0];
	if(!cnt[0]){
		printf("-1\n");
		return 0;
	}
	while(l < r){
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	} if(!check(l)) printf("-1\n");
	else for(i = l; i <= cnt[0]; ++ i)
		printf("%d ", i);
	return 0;
}