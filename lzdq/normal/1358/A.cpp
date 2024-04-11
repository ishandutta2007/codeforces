#include<cstdio>
int n,m;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%d\n",(n*m+1)/2);
	}
	return 0;
}