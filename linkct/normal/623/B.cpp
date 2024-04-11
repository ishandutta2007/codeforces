#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 1000005;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int n, a, b, seq[MAXN], bestpos[MAXN], p[100005];
LL c[MAXN], ans;

inline LL getCost1(int pos){return LL(pos) * a + c[pos + 1];}
LL solve1(int v){
	int i;
	for(i = n; i; -- i)
		if(seq[i] % v == 0) c[i] = c[i + 1];
		else if((seq[i] + 1) % v == 0 || (seq[i] - 1) % v == 0) c[i] = c[i + 1] + b;
		else c[i] = INF;
	//for(i = 1; i <= n; ++ i) printf("c[%d] = %lld\n", i, c[i]);
	bestpos[n] = n;
	for(i = n - 1; i; -- i)
		bestpos[i] = (getCost1(bestpos[i + 1]) < getCost1(i) ? bestpos[i + 1] : i);
	LL ret = c[1], cur = 0LL;
	//printf("init %lld\n", ret);
	for(i = 1; i < n; ++ i){
		//printf("%lld\n", getCost1(bestpos[i + 1]) - LL(i) * a);
		if(seq[i] % v != 0 && ((seq[i] + 1) % v == 0 || (seq[i] - 1) % v == 0)) cur += b;
		else if(seq[i] % v != 0 && (seq[i] + 1) % v != 0 && (seq[i] - 1) % v != 0) cur = INF;
		ret = min(ret, getCost1(bestpos[i + 1]) - LL(i) * a + cur);
	}
	//printf("%d %lld\n", v, ret);
	return ret;
}
inline LL getCost2(int pos){return c[pos - 1] + LL(n - pos + 1) * a;}
LL solve2(int v){
	int i;
	for(i = 1; i <= n; ++ i)
		if(seq[i] % v == 0) c[i] = c[i - 1];
		else if((seq[i] + 1) % v == 0 || (seq[i] - 1) % v == 0) c[i] = c[i - 1] + b;
		else c[i] = INF;
	bestpos[1] = 1;
	for(i = 2; i <= n; ++ i)
		bestpos[i] = (getCost2(bestpos[i - 1]) < getCost2(i) ? bestpos[i - 1] : i);
	LL ret = c[n], cur = 0LL;
	for(i = n; i > 1; -- i){
		if(seq[i] % v != 0 && ((seq[i] + 1) % v == 0 || (seq[i] - 1) % v == 0)) cur += b;
		else if(seq[i] % v != 0 && (seq[i] + 1) % v != 0 && (seq[i] - 1) % v != 0) cur = INF;
		ret = min(ret, getCost2(bestpos[i - 1]) - LL(n - i + 1) * a + cur);
	}
	//printf("rev: %d %lld\n", v, ret);
	return ret;
}
void decompose(int val){
	for(int i = 2; i <= val / i; ++ i)
		if(val % i == 0){
			p[++ p[0]] = i;
			while(val % i == 0) val /= i;
		}
	if(val != 1) p[++ p[0]] = val;
}
int main(){
	int i;
	scanf("%d%d%d", &n, &a, &b);
	ans = INF;//LL(n - 1) * a;
	for(i = 1; i <= n; ++ i) scanf("%d", &seq[i]);
	decompose(seq[1] - 1);
	decompose(seq[1]);
	decompose(seq[1] + 1);
	sort(p + 1, p + 1 + p[0]);
	p[0] = unique(p + 1, p + 1 + p[0]) - p - 1;
	for(i = 1; i <= p[0]; ++ i) ans = min(ans, solve1(p[i]));
	p[0] = 0;
	decompose(seq[n] - 1);
	decompose(seq[n]);
	decompose(seq[n] + 1);
	sort(p + 1, p + 1 + p[0]);
	p[0] = unique(p + 1, p + 1 + p[0]) - p - 1;
	for(i = 1; i <= p[0]; ++ i) ans = min(ans, solve2(p[i]));
	printf("%I64d\n", ans);
	return 0;
}