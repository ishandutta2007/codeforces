#include<cstdio>
int T,n,s,t,a;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&s,&t);
		a=s+t-n;
		s-=a;t-=a;
		printf("%d\n",(s>t?s:t)+1);
	}
}