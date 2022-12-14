#include <cstdio>
typedef long long int ll;
const int MAXN = 100005, MAXK = 13;

ll Bit[MAXK][MAXN], f[MAXN][MAXK];
int n, k, seq[MAXN];

void update(ll bit[], int p, ll v){
	for(; p <= n; p += p & -p)
		bit[p] += v;
}
ll query(ll bit[], int p){
	ll ret = 0LL;
	for(; p; p -= p & -p)
		ret += bit[p];
	return ret;
}
int main(){
	int i, j; ll ans = 0LL;
	scanf("%d%d", &n, &k); ++ k;
	for(i = 1; i <= n; ++ i) scanf("%d", &seq[i]);
	for(i = 1; i <= n; ++ i){
		f[i][1] = 1;
		for(j = 2; j <= k; ++ j)
			f[i][j] = query(Bit[j - 1], seq[i]);
		for(j = 1; j <= k; ++ j)
			update(Bit[j], seq[i], f[i][j]);
		ans += f[i][k];
	}
	printf("%I64d\n", ans);
	return 0;
}