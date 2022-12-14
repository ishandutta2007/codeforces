#include <cstdio>

int main(){
	int i, a[7], ans = 0, lft, rht;
	for(i = 1; i <= 6; ++ i) scanf("%d", &a[i]);
	for(i = 1; i <= a[1] + a[2]; ++ i){
		if(i <= a[2]) lft = - i;
		else lft = i - 2 * a[2] - 1;
		if(i <= a[4]) rht = a[3] * 2 - 2 + i;
		else rht = a[3] * 2 - 1 + a[4] * 2 - i;
		ans += rht - lft + 1;
	}
	printf("%d\n", ans);
	return 0;
}