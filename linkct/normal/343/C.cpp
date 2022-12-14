#include <cstdio>
typedef long long int ll;
const int MAXN = 100005;

int n, m;
ll pos[MAXN], dest[MAXN], TL;

inline ll min(ll a, ll b){return a > b ? b : a;}
bool legal(ll l, ll r, ll cur){
	if(cur <= l) return r - cur <= TL;
	if(cur >= r) return cur - l <= TL;
	return min(cur - l, r - cur) + r - l <= TL;
}
bool check(){
	int i, j, st;
	for(i = 1, j = 0; i <= n; ++ i){
		st = j + 1;
		while(j < m && legal(dest[st], dest[j + 1], pos[i])) j ++;
	}
	return j == m;
}
int main(){
	int i; ll l, r;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i) scanf("%I64d", &pos[i]);
	for(i = 1; i <= m; ++ i) scanf("%I64d", &dest[i]);
	l = 0LL, r = 20000000000LL;
	while(l < r){
		TL = (l + r) >> 1;
		if(check()) r = TL;
		else l = TL + 1;
	}
	printf("%I64d\n", r);
	return 0;
}