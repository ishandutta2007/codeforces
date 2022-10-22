#include<cstdio>
int a,b,d,n,s,t;
main(){
	scanf("%d%d%d",&n,&b,&d);
	while(n--){
		scanf("%d",&a);
		if(a>b)continue;
		t+=a;
		if(t>d)++s,t=0;
	}
	printf("%d",s);
}