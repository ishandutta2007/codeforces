#include <stdio.h>

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int n,d,s,t,t1,i;
	scanf("%d%d",&n,&d);
	t=0;
	for(i=0;i<n;i++){
		scanf("%d",&t1);
		t=t+t1;
	}
	if(t+10*(n-1)<=d){
		printf("%d",2*(n-1)+(d-t-10*(n-1))/5);
	}
	else printf("-1");
}