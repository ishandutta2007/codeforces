#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200005;

char str[MAXN];
int n, g[MAXN], f[MAXN], best[MAXN];

void Manacher(){
	int i, border, id;
	for(i = border = id = 1; i <= n; ++ i){
		f[i] = min(f[id * 2 - i], border - i);
		while(str[i + f[i]] == str[i - f[i]]) ++ f[i];
		if(i + f[i] > border) border = i + f[i], id = i;
	}
}
void getKMP(){
	int i, j; n <<= 1;
	for(i = 2, j = 0; i <= n; ++ i){
		while(j && str[j + 1] != str[i]) j = g[j];
		if(str[j + 1] == str[i]) ++ j;
		g[i] = j;
	} n >>= 1;
}
int main(){
	int i, ans = 0, ansp, tmp;
	scanf("%s", str + 1);
	n = strlen(str + 1);
	str[0] = '$'; Manacher();
	reverse(str + 1, str + 1 + n);
	for(i = n; i; -- i) str[2 * n - i + 1] = str[i];
	getKMP();
	memcpy(g + 1, g + n + 1, sizeof(int) * n);
	for(i = 1; i <= n; ++ i) g[i] = min(g[i], i);
	best[1] = 1;
	for(i = 2; i <= n; ++ i)
		if(g[i] < g[best[i - 1]]) best[i] = best[i - 1];
		else best[i] = i;
	for(i = 1; i <= n; ++ i)
		if(2 * (f[i] + min(g[best[i - f[i]]], n - i - f[i] + 1)) - 1 > ans){
			ans = 2 * (f[i] + min(g[best[i - f[i]]], n - i - f[i] + 1)) - 1;
			ansp = i;
		}
	i = ansp;
	if(tmp = min(g[best[i - f[i]]], n - i - f[i] + 1)){
		printf("3\n");
		printf("%d %d\n%d %d\n%d %d\n", best[i - f[i]] - tmp + 1, tmp, i - f[i] + 1, f[i] * 2 - 1, n - tmp + 1, tmp);
	}else{
		printf("1\n");
		printf("%d %d\n", i - f[i] + 1, f[i] * 2 - 1);
	}
	return 0;
}