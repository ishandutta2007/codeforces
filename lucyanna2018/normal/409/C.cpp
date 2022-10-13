#include<stdio.h>
const int a[5]={1,1,2,7,4};
int main(){
	int res = 999;
	for(int i=0; i<5; i++){
		int now;
		scanf("%d",&now);
		now /= a[i];
		if(now < res)res=now;
	}
	printf("%d\n",res);
	return 0;
}