#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 100005;

struct skl{
	int v, id;
	bool operator < (const skl &rhs) const{
		return v < rhs.v;
	}
}seq[MAXN];
LL pf[MAXN], m;
int n, maxl, cp, cm;

bool cmp(const skl& l, const skl &r){return l.id < r.id;}
LL getVal(int p, LL resource){
	if(!p) return LL(maxl);
	int l = 1, r = p, mid;
	while(l < r){
		mid = (l + r + 1) >> 1;
		if(LL(seq[mid].v) * mid - pf[mid] <= resource) l = mid;
		else r = mid - 1;
	}
	if(r == p) return min((resource + pf[r]) / r, LL(maxl));
	return (resource + pf[r]) / r;
}
int main(){
	int i, ansp; LL ans = -1LL, tmp;
	scanf("%d%d%d%d%I64d", &n, &maxl, &cp, &cm, &m);
	LL m_ = m;
	for(i = 1; i <= n; ++ i){
		scanf("%d", &seq[i].v);
		seq[i].id = i;
	}
	sort(seq + 1, seq + 1 + n);
	seq[n + 1].v = maxl;
	for(i = 1; i <= n; ++ i) pf[i] = pf[i - 1] + seq[i].v;
	for(i = n; i >= 0 && m >= 0LL; -- i){
		if((tmp = getVal(i, m)) * cm + LL(n - i) * cp > ans){
			ans = tmp * cm + LL(n - i) * cp;
			ansp = i;
		}
		m -= maxl - seq[i].v;
	} m = m_;
	for(i = ansp + 1; i <= n; ++ i){
		m -= maxl - seq[i].v;
		seq[i].v = maxl;
	} tmp = getVal(ansp, m);
	for(i = 1; i <= ansp; ++ i) seq[i].v = max(seq[i].v, int(tmp));
	sort(seq + 1, seq + 1 + n, cmp);
	printf("%I64d\n", ans);
	for(i = 1; i <= n; ++ i) printf("%d ", seq[i].v);
	return 0;
}