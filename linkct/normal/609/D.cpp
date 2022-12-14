#include <cstdio>
#include <queue>
#define fi first
#define se second
using namespace std;
const int MAXN = 200005;
typedef long long int LL;
typedef pair <LL, int> pli;

int n, m, k, a[MAXN], pfa[MAXN], b[MAXN], pfb[MAXN], type[MAXN], cost[MAXN];
LL s;
priority_queue <pli> h;

bool check(int limit){
	int i;
	LL pra = a[pfa[limit]], prb = b[pfb[limit]], sum = 0LL;
	while(!h.empty()) h.pop();
	for(i = 1; i <= m; ++ i){
		if(type[i] == 1){
			h.push(pli(pra * cost[i], i));
			sum += pra * cost[i];
		}else{
			h.push(pli(prb * cost[i], i));
			sum += prb * cost[i];
		}
		if(sum > s){
			sum -= h.top().fi;
			h.pop();
		}
	}
	return int(h.size()) >= k;
}
int main(){
	int i, l, r, mid;
	scanf("%d%d%d%I64d", &n, &m, &k, &s);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		pfa[i] = i;
		if(i != 1 && a[pfa[i - 1]] < a[i]) pfa[i] = pfa[i - 1];
	}
	for(i = 1; i <= n; ++ i){
		scanf("%d", &b[i]);
		pfb[i] = i;
		if(i != 1 && b[pfb[i - 1]] < b[i]) pfb[i] = pfb[i - 1];
	}
	for(i = 1; i <= m; ++ i)
		scanf("%d%d", &type[i], &cost[i]);
	l = 1, r = n;
	while(l < r){
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(check(r)){
		printf("%d\n", r);
		while(int(h.size()) > k) h.pop();
		while(!h.empty()){
			printf("%d %d\n", h.top().se, (type[h.top().se] == 1 ? pfa[r] : pfb[r]));
			h.pop();
		}
	}else printf("-1\n");
	return 0;
}