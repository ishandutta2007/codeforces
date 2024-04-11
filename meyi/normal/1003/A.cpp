#include<cstdio>
int a,m[101],n,s;
main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		s=(++m[a]>s?m[a]:s);
	}
	printf("%d",s);
}