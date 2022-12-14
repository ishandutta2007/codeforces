#include <cstdio>
#include <cstring>
const int init[7] = {0, 1, 0, 1, 2, 0, 2};

int sg1(int x){
	if(x <= 2) return x;
	return (x & 1) ^ 1;
}
int sg2(int x){
	if(x <= 6) return init[x];
	return x & 1 ? (sg2(x - 1) ? 0 : 1) : (((x >> 1) & 1) ? 1 : (((sg2(x >> 1) - 1) ^ 1) + 1));
}
int main(){
	int i, t, n, k, res = 0;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		if(k & 1) res ^= sg2(t);
		else res ^= sg1(t);
	}
	printf("%s\n", res ? "Kevin" : "Nicky");
	return 0;
}