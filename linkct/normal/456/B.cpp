#include <cstdio>
#include <cstring>

bool vis[15][15];
int p[15][15];
char str[100005];

inline int quickPow(int base, int k){
	if(vis[base][k]) return p[base][k];
	vis[base][k] = true;
	int& ret = p[base][k];
	ret = 1;
	while(k){
		if(k & 1) ret = (ret * base) % 5;
		base = (base * base) % 5;
		k >>= 1;
	}
	return ret;
}
int main(){
	int i, j, len, ans = 0, temp, base;
	scanf("%s", str + 1);
	len = strlen(str + 1);
	for(i = 1; i <= 4; ++ i){
		temp = 1, base = i;
		for(j = len; j; -- j){
			temp = (temp * quickPow(base, str[j] - '0')) % 5;
			base = quickPow(base, 10);
		}
		ans += temp;
	}
	printf("%d\n", ans % 5);
	return 0;
}