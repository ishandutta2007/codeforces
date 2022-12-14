#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 100005;

int n, k, seq[MAXN]; LL pf[MAXN];

LL count(LL x){
	int i; LL ret = 0;
	map <LL, int> cnt;
	cnt[0] = 1;
	for(i = 1; i <= n; ++ i){
		ret += cnt[pf[i] - x];
		++ cnt[pf[i]];
	} return ret;
}
int main(){
	int i; LL pos, neg, p, ans = 0, limit;
	scanf("%d%d", &n, &k);
	pos = neg = 0;
	for(i = 1; i <= n; ++ i){
		scanf("%d", &seq[i]);
		pf[i] = pf[i - 1] + seq[i];
		if(seq[i] > 0) pos += seq[i];
		else neg += seq[i];
	} limit = max(pos, - neg);
	if(k == 1){printf("%I64d\n", count(1)); return 0;}
	if(k == -1){printf("%I64d\n", count(1) + count(-1)); return 0;}
	for(p = 1; abs(p) <= limit; p *= k)
		ans += count(p);
	printf("%I64d\n", ans);
	return 0;
}