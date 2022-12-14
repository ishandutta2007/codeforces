#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL MOD = 1000000007LL;
const int MAXN = 100005;

int n, deg[MAXN];

inline LL quickPow(LL base, int times){
	LL ret = 1LL;
	while(times){
		if(times & 1) ret = (ret * base) % MOD;
		base = (base * base) % MOD;
		times >>= 1;
	} return ret;
}
int main(){
	int i, u, v, lcnt = 0; LL pw;
	scanf("%d", &n);
	for(i = 1; i < n; ++ i){
		scanf("%d%d", &u, &v);
		++ deg[u], ++ deg[v];
	}
	for(i = 1; i <= n; ++ i)
		if(deg[i] == 1) ++ lcnt;
	pw = quickPow(2, n - lcnt);
	printf("%d\n", int((lcnt * pw * 2 + (n - lcnt) * pw) % MOD));
	return 0;
}