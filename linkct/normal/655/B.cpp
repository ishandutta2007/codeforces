#include <cstdio>
typedef long long int LL;
const int MAXN = 100005;

int n, k, p[MAXN], bit[MAXN];

int query(int x){
	int ret = 0;
	for(; x; x -= x & -x)
		ret += bit[x];
	return ret;
}
void update(int x){
	for(; x <= n; x += x & -x)
		++ bit[x];
}
int main(){
	int i, t; LL ans = 0LL;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; ++ i) p[i] = i;
	for(i = 1; i <= n / 2 && i <= k; ++ i){
		t = p[i];
		p[i] = p[n - i + 1];
		p[n - i + 1] = t;
	}
	for(i = n; i; -- i){
		ans += query(p[i]);
		update(p[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}