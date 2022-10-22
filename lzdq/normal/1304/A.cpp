#include<cstdio>
int x,y,a,b;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if((y-x)%(a+b)) puts("-1");
		else printf("%d\n",(y-x)/(a+b));
	}
	return 0;
}