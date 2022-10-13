#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int tot = 0, L = -2147483647, R = 2147483647;
	for(int i=0; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(y == 1){
			L = max(L, 1900 - tot);
		}else{
			R = min(R, 1899 - tot);
		}
		tot += x;
	}
	if(L <= R){
		if(R == 2147483647)
			puts("Infinity");
		else
			printf("%d\n", R + tot);
	}
	else
		puts("Impossible");
	return 0;
}