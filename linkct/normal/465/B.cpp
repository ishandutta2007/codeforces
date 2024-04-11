#include <cstdio>
int n, seq[1005];
int main(){
	int i, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &seq[i]);
		if(seq[i]) ans ++;
		else if(seq[i - 1]) ans ++;
	}
	if(seq[n]) ans ++;
	printf("%d\n", ans ? ans - 1 : 0);
	return 0;
}