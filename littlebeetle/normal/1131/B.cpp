#include<cstdio>
int n,a,b,x,y,ans=1;
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		ans+=max(0,min(x,y)-max(a,b)+1)-(a==b);
		a=x;b=y;
	}
	printf("%d\n",ans);
}