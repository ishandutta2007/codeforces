#include <cstdio>

int n, m, k, s[1005];

inline int bitCount(int x){
	int ret = 0;
	while(x){
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}
int main(){
	int i, ans = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 1; i <= m + 1; ++ i)
		scanf("%d", &s[i]);
	for(i = 1; i <= m; ++ i)
		if(bitCount(s[i] ^ s[m + 1]) <= k) ans ++;
	printf("%d\n", ans);
	return 0;
}