#include<cstdio>
int n,l,p,t,s,u,v;
int main(){
	scanf("%d%d%d",&n,&l,&p);
	while(n--){
		scanf("%d%d",&u,&v);
		s+=(u-t)/p;
		t=u+v;
	}//
	s+=(l-t)/p;
	printf("%d",s);
	return 0;
}