#include <cstdio>
const int MAXN = 100005;

int n, seq[MAXN];

int main(){
	int i, t, cnt, prev; char x;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		while((x = getchar()) != '0' && x != '1') ;
		t = x - '0';
		if(i == 1) prev = t, cnt = 1;
		else if(t == prev) ++ cnt;
		else{
			seq[++ seq[0]] = cnt;
			cnt = 1; prev = t;
		}
	} seq[++ seq[0]] = cnt;
	for(i = 1; i <= seq[0]; ++ i)
		if(seq[i] >= 3) break;
	if(i <= seq[0]){
		printf("%d\n", seq[0] + 2);
		return 0;
	}
	for(i = 1, cnt = 0; i <= seq[0]; ++ i)
		if(seq[i] == 2) ++ cnt;
	if(cnt >= 2){
		printf("%d\n", seq[0] + 2);
		return 0;
	}
	printf("%d\n", seq[0] + cnt);
	return 0;
}