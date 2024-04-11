#include <cstdio>
#include <cstring>
const int MAXN = 1000005, MOD = 1000000007;
typedef long long int ll;

int f[MAXN], n, m, len, pos[MAXN];
char str[MAXN];

inline int max(int a, int b){return a > b ? a : b;}
inline int quickPow(int base, int k){
	int ret = 1;
	while(k){
		if(k & 1) ret = ((ll)ret * base) % (ll)MOD;
		base = ((ll)base * base) % (ll)MOD;
		k >>= 1;
	}
	return ret;
}
void getEXKMP(){
	int i, j, border;
	for(i = 2; i <= len; ++ i)
		if(str[i] != str[i - 1]) break;
	f[2] = i - 2;
	border = 2;
	for(i = 3; i <= len; ++ i){
		if(border + f[border] - 1 < i){
			for(j = i; j <= len; ++ j)
				if(str[j - i + 1] != str[j]) break;
			f[i] = j - i;
			border = i;
			continue;
		}
		if(i + f[i - border + 1] < border + f[border]) f[i] = f[i - border + 1];
		else{
			for(j = border + f[border]; j <= len; ++ j)
				if(str[j - i + 1] != str[j]) break;
			f[i] = j - i;
		}
		if(border + f[border] <= i + f[i]) border = i;
	}
}
int main(){
	int i, ans = 0;
	scanf("%d%d%s", &n, &m, str + 1);
	len = strlen(str + 1);
	pos[0] = 1 - len;
	pos[m + 1] = n + 1;
	getEXKMP();
	for(i = 1; i <= m; ++ i){
		scanf("%d", &pos[i]);
		ans += max(pos[i] - pos[i - 1] - len, 0);
		if(pos[i] - pos[i - 1] >= len) continue;
		if(pos[i] - pos[i - 1] + f[pos[i] - pos[i - 1] + 1] < len){
			printf("0\n");
			return 0;
		}
	}
	ans += max(pos[m + 1] - pos[m] - len, 0);
	printf("%d\n", quickPow(26, ans));
	return 0;
}