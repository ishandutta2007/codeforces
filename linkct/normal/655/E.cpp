#include <cstdio>
const int MAXN = 2000005, MOD = 1000000007;

int n, k, f[MAXN], last[35], minv, g[MAXN];
char str[MAXN];

int main(){
	int i, j;
	scanf("%d%d%s", &n, &k, str + 1);
	for(i = 1; str[i]; ++ i) last[str[i] - 'a'] = i;
	n += i - 1; last[26] = MAXN;
	for(; i <= n; ++ i){
		for(j = 0, minv = 26; j < k; ++ j)
			if(last[j] < last[minv]) minv = j;
		str[i] = minv + 'a';
		last[minv] = i;
	}
	for(i = 0; i < k; ++ i) last[i] = 0;
	f[1] = g[1] = 1; last[str[1] - 'a'] = 1;
	for(i = 2; i <= n; ++ i){
		g[i] = f[i - 1] + 1; if(g[i] >= MOD) g[i] -= MOD;
		f[i] = g[i] + f[i - 1] - g[last[str[i] - 'a']];
		if(f[i] >= MOD) f[i] -= MOD;
		else if(f[i] < 0) f[i] += MOD;
		last[str[i] - 'a'] = i;
	}
	printf("%d\n", (f[n] + 1) % MOD);
	return 0;
}