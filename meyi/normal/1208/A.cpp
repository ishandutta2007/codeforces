#include<cstdio>
int f[3],n,t;
main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",f,f+1,&n);
		f[2]=*f^f[1];
		printf("%d\n",f[n%3]);
	}
}