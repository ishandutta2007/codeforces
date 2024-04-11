#include<stdio.h>
int main(){
	int x,r=0,n,m;
	for(scanf("%d",&n); n--;){
		scanf("%d",&x);
		r+=x;
	}
	for(scanf("%d",&m); m--;){
		int L,R;
		scanf("%d%d",&L,&R);
		if(L>=r){
			printf("%d\n",L);
			return 0;
		}else
		if(R>=r){
			printf("%d\n",r);
			return 0;
		}
	}
	puts("-1");
	return 0;
}