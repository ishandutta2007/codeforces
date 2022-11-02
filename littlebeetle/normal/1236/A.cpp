#include<cstdio>
int T,a,b,c,x,y;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		y=min(b,c/2);
		b-=y;
		x=min(a,b/2);
		printf("%d\n",(x+y)*3);
	}
}