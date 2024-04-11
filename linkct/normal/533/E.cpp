#include <cstring>
#include <cstdio>
const int MAXN = 100005;

int n;
char str1[MAXN], str2[MAXN], tstr1[MAXN], tstr2[MAXN];

int main(){
	int i, cnt = 0, pos, ans = 0;
	scanf("%d%s%s", &n, str1 + 1, str2 + 1);
	for(i = n; i >= 1; -- i)
		if(str1[i] != str2[i]){
			cnt ++;
			if(cnt == 1) pos = i;
		}
	if(cnt == 1){
		printf("2\n");
		return 0;
	}
	cnt = 0;
	for(i = 1; i <= n; ++ i)
		if(i != pos){
			tstr1[++ cnt] = str1[i];
			tstr2[cnt] = str2[i];
		}
	cnt = 1;
	for(i = 1; i <= n; ++ i)
		if(tstr1[cnt] == str2[i])
			cnt ++;
	if(cnt == n) ans ++;
	cnt = 1;
	for(i = 1; i <= n; ++ i)
		if(tstr2[cnt] == str1[i])
			cnt ++;
	if(cnt == n) ans ++;
	printf("%d\n", ans);
	return 0;
}