#include <cstdio>
const int MAXN = 1005;

int n;
char str[MAXN];

inline int min(int a, int b){return a > b ? b : a;}
int solve(){
	int i, ret, tmp = 0, cnt = 0;
	for(i = 1; i <= n; ++ i)
		if(str[i] == 'H') ++ cnt;
	for(i = 1; i <= cnt; ++ i)
		tmp += int(str[i] != 'H');
	ret = tmp;
	for(i = n, tmp = 0; i > n - cnt; -- i)
		tmp += int(str[i] != 'H');
	return min(ret, tmp);
}
int main(){
	int i, j, ans = MAXN; char tmp;
	scanf("%d%s", &n, str + 1);
	for(i = 1; i <= n; ++ i){
		ans = min(ans, solve());
		tmp = str[1];
		for(j = 1; j < n; ++ j) str[j] = str[j + 1];
		str[n] = tmp;
	}
	printf("%d\n", ans);
	return 0;
}